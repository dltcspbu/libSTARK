def binary_string_to_int(string1):
	# print(string1)
	string2 = string1[1:len(string1)-1].split(' ')
	valueInMemory=0
	if string2!=['']:
		for i in range(len(string2)):
			valueInMemory+=int(string2[i])*pow(2,i)
	return valueInMemory