import pprint
import pandas as pd

def getData(i): 
    import pymongo
    #connect to db
    client = pymongo.MongoClient('mongodb://localhost:27017/')

    #make smth with db
    with client:

        db = client.testdb
            
        # quantity = db.transactions.find().count()
        # for i in range(quantity):
        transac = db.transactions.find_one({'transaction_ID': i+1})
        fromID = transac["fromUser_ID"]
        toID = transac["toUser_ID"]
        value = transac["value"]
        cashID = transac["nameCash"]
        # print(fromID, toID, value, cashID)
        us = db.users.find_one({'user_ID': fromID})
        fromCash = us[cashID]
        us = db.users.find_one({'user_ID': toID})
        toCash = us[cashID]
        # print(fromCash, "suck1")
        # print(toCash, "suck2")
        print("-----------------------------")
        users_list = list(db.users.find())
        df = pd.DataFrame(users_list)
        print("getDATA")
        print(df)
    return(fromID, toID, fromCash, toCash, value, cashID)
    
def updateDB(fromCash, toCash, fromID, toID, cashID):
    import pymongo
    client = pymongo.MongoClient('mongodb://localhost:27017/')
    with client:
        db = client.testdb
        db.users.update_one({'user_ID': fromID}, {'$set': {cashID : fromCash}})
        db.users.update_one({'user_ID': toID}, {'$set': {cashID : toCash}})
    users_list = list(db.users.find())
    df = pd.DataFrame(users_list)
    print(df)
    # pprint.pprint(list(db.users.find()))

def getQuantityTransaction():
    import pymongo
    client = pymongo.MongoClient('mongodb://localhost:27017/')
    with client:
        db = client.testdb
        quantity = db.transactions.find().count()
    return (quantity)

def addBackupData():
     import pymongo
     client = pymongo.MongoClient('mongodb://localhost:27017/')
     with client:
        db = client.testdb
        db.usersBackup.insert_many(db.users.find())
        print("------------------------")
        users_list = list(db.users.find())
        df = pd.DataFrame(users_list)
        print("users")
        print(df)
        print("------------------------------")
        users_list = list(db.usersBackup.find())
        df = pd.DataFrame(users_list)
        print("BackUpUsers")
        print(df)
        print("---------------------------")
          
    # with client:
    #     db = client.testdb
    #     db.usersBackup.insert_many(users)

def callBackup():
    import pymongo
    client = pymongo.MongoClient('mongodb://localhost:27017/')
     # client = pymongo.MongoClient('mongodb://localhost:27017/')
    with client:
        db = client.testdb
        db.users.drop()
        # print("fucksuckfuck")
        # print(list(db.usersBackup.find()))
        db.users.insert_many(db.usersBackup.find())
        db.usersBackup.drop()

def deleteBackupData():
    import pymongo
    client = pymongo.MongoClient('mongodb://localhost:27017/')
    with client:
        db = client.testdb
        db.usersBackup.drop()
    
def printDB():
    import pymongo
    client = pymongo.MongoClient('mongodb://localhost:27017/')
    with client:
        db = client.testdb
        users_list = list(db.users.find())
        df = pd.DataFrame(users_list)
        print("result DB after Transactions")
        print(df)
        print("----------------------------")

def cleanUpForTesting():
    import pymongo
    client = pymongo.MongoClient('mongodb://localhost:27017/')
     #add test data
    users = [
    {'user_ID':1 , 'cash1':10 , 'cash2':20 , 'cash3':0 , 'cash4':0 },
    {'user_ID':2 , 'cash1':10 , 'cash2':20 , 'cash3':0 , 'cash4':0 },
    {'user_ID':3 , 'cash1':10 , 'cash2':20 , 'cash3':30 , 'cash4':0 },
    {'user_ID':4 , 'cash1':0 , 'cash2': 20, 'cash3':30 , 'cash4':0 },
    {'user_ID':5 , 'cash1':0 , 'cash2':20 , 'cash3':30 , 'cash4':40 },
    {'user_ID':6 , 'cash1':0 , 'cash2':0 , 'cash3':30 , 'cash4':40 },
    {'user_ID':7 , 'cash1':0 , 'cash2':0 , 'cash3':30 , 'cash4':40 },
    {'user_ID':8 , 'cash1':0 , 'cash2':0 , 'cash3':0 , 'cash4':40 },
    {'user_ID':9 , 'cash1':10 , 'cash2':0 , 'cash3':0 , 'cash4':40 },
    {'user_ID':10 , 'cash1':10 , 'cash2':0, 'cash3':0 , 'cash4':40 }
    ]

    testtransactions = [
    {'transaction_ID':1 , 'fromUser_ID':1 , 'toUser_ID':2 , 'value':10 , 'nameCash':'cash1' },
    {'transaction_ID':2 , 'fromUser_ID':4 , 'toUser_ID':9 , 'value':9 , 'nameCash':'cash3' }
    # {'transaction_ID':3 , 'fromUser_ID': , 'toUser_ID': , 'value': , 'nameCash': }
    # {'transaction_ID':4 , 'fromUser_ID': , 'toUser_ID': , 'value': , 'nameCash': }
    # {'transaction_ID':5 , 'fromUser_ID': , 'toUser_ID': , 'value': , 'nameCash': }
    # {'transaction_ID':6 , 'fromUser_ID': , 'toUser_ID': , 'value': , 'nameCash': }
    # {'transaction_ID':7 , 'fromUser_ID': , 'toUser_ID': , 'value': , 'nameCash': }
    # {'transaction_ID':8 , 'fromUser_ID': , 'toUser_ID': , 'value': , 'nameCash': }
    # {'transaction_ID':9 , 'fromUser_ID': , 'toUser_ID': , 'value': , 'nameCash': }
    # {'transaction_ID':10 , 'fromUser_ID': , 'toUser_ID': , 'value': , 'nameCash': }
    # {'transaction_ID':11 , 'fromUser_ID': , 'toUser_ID': , 'value': , 'nameCash': }
    # {'transaction_ID':12 , 'fromUser_ID': , 'toUser_ID': , 'value': , 'nameCash': }
    # {'transaction_ID':13 , 'fromUser_ID': , 'toUser_ID': , 'value': , 'nameCash': }
    # {'transaction_ID':14 , 'fromUser_ID': , 'toUser_ID': , 'value': , 'nameCash': }
    ]

    with client:
        db = client.testdb
        db.transactions.drop()
        db.transactions.insert_many(testtransactions)
        db.users.drop()
        db.users.insert_many(users)
        db.usersBackup.drop()

        users_list = list(db.users.find())
        df = pd.DataFrame(users_list)
        print("cleanUpForTesting")
        print(df)
        print("------------------------------------------")



