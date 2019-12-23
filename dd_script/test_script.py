#!/usr/bin/env python3

import subprocess
from create_tinyram_code import create_tinyram_code
import test_string_work
import test_db_script
import time

#add testing security params
security_value1 = 5
security_value2 = 10
security_param1 = '-t' + str(security_value1)  
security_param2 = '-s' + str(security_value2)
#add params for fixed string
opportunityTransactionStringNumber = 3
valueOfFirstUsersCashStringNumber = 1
valueOfSecondUsersCashStringNumber = 2
stringOpportunity = "can make this transaction"
stringCash1Check = "new cash is : "
stringCash2Check = "new cash is : "

startTime = time.time()

test_db_script.cleanUpForTesting()
test_db_script.addBackupData()
quantity_transaction = test_db_script.getQuantityTransaction()

#-------------------------------------------------------------------------------------------
#try to include db
for i in range(quantity_transaction):
	print("transaction", i)
	data = test_db_script.getData(i)
	fromID = data[0]
	toID = data[1]
	cashFrom = data[2]
	cashTo = data[3]
	cashValue = data [4]
	cashID = data [5]

	tinyram_code = create_tinyram_code(cashFrom, cashTo, cashValue)
	
	#run tinyram
	p = subprocess.Popen(["./../stark-tinyram", tinyram_code, security_param1, security_param2], stdout=subprocess.PIPE)
	output, err = p.communicate()
	output = output.decode('utf-8')
	lines = output.split('\n')

	#get string from tunyRAM output
	inputOpportunityString = lines[opportunityTransactionStringNumber]
	inputFirstCash = lines[valueOfFirstUsersCashStringNumber]
	inputSecondCash = lines[valueOfSecondUsersCashStringNumber]

	#chech that we "can make this transaction"
	if inputOpportunityString[:len(inputOpportunityString)] == stringOpportunity:
		#check binarystring with user's cash
		#first user cash 
		if (inputFirstCash[:14]) == stringCash1Check:
			#add new user's 1 cash
			cashFrom = test_string_work.binary_string_to_int(inputFirstCash[14:len(inputFirstCash)])
		#second user cash
		if inputSecondCash[:14] == stringCash2Check:
			#add new user's 2 cash
			cashTo = test_string_work.binary_string_to_int(inputSecondCash[14:len(inputSecondCash)])
		if i == quantity_transaction-1:
			print("transaction completed successfully")
			
		test_db_script.updateDB(cashFrom, cashTo, fromID, toID, cashID)

	else:
		print("ERROR: can't make transaction")
		test_db_script.callBackup()
		break

test_db_script.deleteBackupData()
test_db_script.printDB()
print("time", "--- %s seconds ---" % (time.time() - startTime))

#end of try include db
#-----------------------------------------------------------------------------------------------------------------------