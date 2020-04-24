# py3.8


def generic_decorator(func):
	
	def wrapper(*args, **kwargs):
		print("do something: start")
		result = func()
		print("do something: stop")
		return result

	return wrapper



@generic_decorator
def concrete_component():
	print("concrete_component")



if __name__ == '__main__':
    concrete_component()
