#include <iostream>
#include <string>


class Command {
public:
    virtual ~Command() {
    }
    virtual void Execute() const = 0;
};


/******************************************************************************
 * The Receiver classes contain some important business logic. They know how to
 * perform all kinds of operations, associated with carrying out a request. In
 * fact, any class may serve as a Receiver.
 *
 * `receiver`负责具体的业务逻辑, 它和`简单的具体命令对象`一样.   
 ******************************************************************************/
class Receiver {
public:
    void DoSomething(const std::string& a) {
        std::cout << "Receiver: Working on (" << a << ".)\n";
    }
    void DoSomethingElse(const std::string& b) {
        std::cout << "Receiver: Also working on (" << b << ".)\n";
    }
};


/******************************************************************************
 *
 * `简单的具体命令对象` 直接实现具体逻辑
 *
 ******************************************************************************/
class SimpleCommand : public Command {
private:
    std::string pay_load_;

public:
    explicit SimpleCommand(std::string pay_load) : pay_load_(pay_load) {}
    void Execute() const override {
        std::cout << "SimpleCommand: See, I can do simple things like printing (" << this->pay_load_ << ")\n";
    }
};




/******************************************************************************
 * A command object knows about receiver and invokes a method of the receiver.    
 * Values for parameters of the receiver method are stored in the command.   
 *
 * The receiver object to execute these methods is also stored in the command object by aggregation.      
 * The receiver then does the work when the execute() method in command is called.     
 *
 ******************************************************************************/
class ComplexCommand : public Command {
private:
    Receiver * receiver_;

    // Context data, required for launching the receiver's methods.
    std::string a_;
    std::string b_;

public:
    ComplexCommand(Receiver* receiver, std::string a, std::string b) : receiver_(receiver), a_(a), b_(b) {}

    // Commands can delegate to any methods of a receiver.
    void Execute() const override {
        std::cout << "ComplexCommand: Complex stuff should be done by a receiver object.\n";
        this->receiver_->DoSomething(this->a_);
        this->receiver_->DoSomethingElse(this->b_);
    }
};


/******************************************************************************
 *
 * Invoker 负责保存命令顺序列表, 通过该列表可以做事务回滚.
 *
 ******************************************************************************/
class Invoker {
private:
    // The invoker does not know anything about a concrete command, it knows only about the command interface.
    Command* on_start_;
    Command* on_finish_;

public:
    ~Invoker() {
        delete on_start_;
        delete on_finish_;
    }

    void SetOnStart(Command* command) {
        this->on_start_ = command;
    }
    void SetOnFinish(Command* command) {
        this->on_finish_ = command;
    }

    // An invoker object knows how to execute a command, and optionally does bookkeeping about the command execution.    
    void DoSomethingImportant() {
        std::cout << "Invoker: Does anybody want something done before I begin?\n";
        if (this->on_start_) {
            this->on_start_->Execute();
        }
        std::cout << "Invoker: ...doing something really important...\n";
        std::cout << "Invoker: Does anybody want something done after I finish?\n";
        if (this->on_finish_) {
            this->on_finish_->Execute();
        }
    }
};


/*
 * The client code can parameterize an invoker with any commands.
 */
int main() {
    Invoker* invoker = new Invoker;
    invoker->SetOnStart(new SimpleCommand("Say Hi!"));
    Receiver* receiver = new Receiver;
    invoker->SetOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));
    invoker->DoSomethingImportant();

    delete invoker;
    delete receiver;

    return 0;
}
