import sqlite3





class DataBase:
    def __init__(self,base) -> None:
        self.connect = sqlite3.Connection((base + ".db"))
        self.cursor = self.connect.cursor()
        self.cursor.execute("""CREATE TABLE IF NOT EXISTS BuyUsers(
                                idDiscord INT,
                                bill INT,
                                sub TEXT
                                )""")
                
        self.cursor.execute("""CREATE TABLE IF NOT EXISTS Users(
                                sub TEXT,
                                time INT,
                                key TEXT,
                                hwid TEXT,
                                ip TEXT,
                                status TEXT
                                )""")
        

    def SelectBuyUser(self,userId):
        with self.connect:
            if self.cursor.execute(f"SELECT idDiscord FROM BuyUsers WHERE  idDiscord = {userId}").fetchone() is None:
                return False
            return True
        
    def InitBuyUser(self,uesrId):
        with self.connect:
            if self.cursor.execute(f"SELECT idDiscord FROM BuyUsers WHERE  idDiscord = {uesrId}").fetchone() is None:
                self.cursor.execute(f"INSERT INTO `BuyUsers` (`idDiscord`)  VALUES (?)",(uesrId,))

    def SelectBuyBill(self,userId):
        with self.connect:
            if self.cursor.execute(f"SELECT idDiscord FROM BuyUsers WHERE  idDiscord = {userId}").fetchone() is None:
                return False
            return self.cursor.execute(f"SELECT bill FROM BuyUsers WHERE  idDiscord = {userId}").fetchone()[0]
   
    def InitBuyBill(self,userId,bill):
        self.InitBuyUser(userId)
        with self.connect:
            if self.cursor.execute(f"SELECT bill FROM BuyUsers WHERE  idDiscord = {userId}").fetchone() is None:
                self.cursor.execute(f"INSERT INTO `BuyUsers` (`bill`)  VALUES (?) WHERE  idDiscord = {userId}",(bill,))
            else:
                self.cursor.execute(f"UPDATE BuyUsers SET bill = ? WHERE idDiscord = ?",(bill,userId))
    
   
    def InitBuySubscription(self,userId,subscription):
        self.InitBuyUser(userId)
        with self.connect:
            if self.cursor.execute(f"SELECT sub FROM BuyUsers WHERE  idDiscord = {userId}").fetchone() is None:
                self.cursor.execute(f"INSERT INTO `BuyUsers` (`sub`)  VALUES (?) WHERE  idDiscord = {userId}",(subscription,))
            else:
                self.cursor.execute(f"UPDATE BuyUsers SET sub = ? WHERE idDiscord = ?",(subscription,userId))

    def SelectBuySubscription(self,userId):
        self.InitBuyUser(userId)
        with self.connect:
            if self.cursor.execute(f"SELECT sub FROM BuyUsers WHERE  idDiscord = {userId}").fetchone() is None:
                return False
            return self.cursor.execute(f"SELECT sub FROM BuyUsers WHERE  idDiscord = {userId}").fetchone()[0]
        



    def SelecteStatus(self,userId):
        self.InitBuyUser(userId)
        with self.connect:
            if self.cursor.execute(f"SELECT status FROM Users WHERE  key = {userId}").fetchone() is None:
                return False
            return self.cursor.execute(f"SELECT status FROM Users WHERE  key = {userId}").fetchone()[0]
        
    def InitStatus(self,key,status):
        with self.connect:
            if self.cursor.execute(f"SELECT status FROM Users WHERE  key = '{key}'").fetchone() is None:
                self.cursor.execute(f"INSERT INTO `Users` (`status`)  VALUES (?) WHERE  key = '{key}'",(status,))
            else:
                self.cursor.execute(f"UPDATE Users SET status = ? WHERE key = ?",(status,key))

    def SelecteTime(self,userId):
        self.InitBuyUser(userId)
        with self.connect:
            if self.cursor.execute(f"SELECT time FROM Users WHERE  key = {userId}").fetchone() is None:
                return False
            return self.cursor.execute(f"SELECT time FROM Users WHERE  key = {userId}").fetchone()[0]
        
    def InitTime(self,key,subscription):
        with self.connect:
            if self.cursor.execute(f"SELECT time FROM Users WHERE  key = '{key}'").fetchone() is None:
                self.cursor.execute(f"INSERT INTO `Users` (`time`)  VALUES (?) WHERE  key = {key}",(subscription,))
            else:
                self.cursor.execute(f"UPDATE Users SET time = ? WHERE key = ?",(subscription,key))
  
    def InitKey(self,key):
        with self.connect:
                self.cursor.execute(f"INSERT INTO `Users` (`key`)  VALUES (?)",(key,))

    def SelectKey(self,key):
        with self.connect:
            if self.cursor.execute(f"SELECT key FROM Users WHERE  key = '{key}'").fetchone() is None:
                return False
            return True
        
    def InitUsersSubscription(self,key,subscription):
        with self.connect:
            if self.cursor.execute(f"SELECT sub FROM Users WHERE  key = '{key}'").fetchone() is None:
                self.cursor.execute(f"INSERT INTO `Users` (`sub`)  VALUES (?) WHERE  key = {key}",(subscription,))
            else:
                self.cursor.execute(f"UPDATE Users SET sub = ? WHERE key = ?",(subscription,key))

