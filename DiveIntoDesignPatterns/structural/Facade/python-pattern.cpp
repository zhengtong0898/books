#include <memory>
#include <string>

class CPU {
public:
    void Freeze() {}
    void Jump(long position) {}
    void Execute() {}
};

class HardDrive {
public:
    std::string Read(long lba, int size) { return "Readed"; }
};

class Memory {
public:
    void Load(long position, std::string data) {}
};

// Facade:
class ComputerFacade {
public:
    void Start() {
        cpu_->Freeze();
        memory_->Load(0x00, hard_drive_->Read(100, 1024));
        cpu_->Jump(0x00);
        cpu_->Execute();
    }

private:
    std::unique_ptr<CPU> cpu_ = std::make_unique<CPU>();
    std::unique_ptr<Memory> memory_ = std::make_unique<Memory>();
    std::unique_ptr<HardDrive> hard_drive_ = std::make_unique<HardDrive>();
};

int main() {
    ComputerFacade computer;
    computer.Start();
}