import sqlite3


class DataBase:
    def __init__(self, name_base : str):
        self.connection = sqlite3.connect(name_base,check_same_thread=False)
        self.cursor = self.connection.cursor()
        self.cursor.execute("""CREATE TABLE IF NOT EXISTS Users(
                                sub TEXT,
                                time INT,
                                key TEXT,
                                hwid TEXT,
                                ip TEXT,
                                status TEXT
                                )""")

    
        

    def ExecuteHwid(self,string : str):
        with self.connection:
            if self.cursor.execute(f"SELECT hwid FROM Users WHERE hwid = {string}").fetchone() is  None:
                return False
            return True
    def IsBaned(self, hwid : str):
        with self.connection:
            if self.cursor.execute(f"SELECT status FROM Users WHERE hwid = {hwid}").fetchone() is None:
                return "NONE"
            return self.cursor.execute(f"SELECT status FROM Users WHERE hwid = {hwid}").fetchone()[0]
        
    def IsBannedIP(self, ip: str):
        with self.connection:
            if self.cursor.execute(f"SELECT status FROM Users WHERE ip = '{ip}'").fetchone() is None:
                return "NONE"
            return self.cursor.execute(f"SELECT status FROM Users WHERE ip = '{ip}'").fetchone()[0]

    def IsCheckKey(self, key : str, hwid : str, ip : str): 
        with self.connection:
            if(self.cursor.execute(f"SELECT key FROM Users WHERE key = '{key.strip()}'").fetchone() is None):
                print("[LOG] key is None")
                return "ERROR"
            
            elif self.cursor.execute(f"SELECT hwid FROM Users WHERE key = '{key.strip()}'").fetchone()[0] is None:
                if(self.cursor.execute(f"SELECT ip FROM Users WHERE key = '{key.strip()}'").fetchone()[0] is None):

                    print("ADD USERS")

                    self.AddHwid(hwid=hwid,key=key)
                    self.AddIp(ip=ip,key=key)
                    return True
            
            elif((self.cursor.execute(f"SELECT hwid FROM Users WHERE key = '{key}'").fetchone()[0] == hwid.strip()) and (self.cursor.execute(f"SELECT ip FROM Users WHERE key = '{key}'").fetchone()[0] == ip.strip())):
                 return True
            
            return False
        

    def AddHwid(self,hwid : str,key : str):
        with self.connection:
            self.cursor.execute("UPDATE Users SET hwid = ? WHERE key = ?", (hwid, key))
    
    def AddIp(self,ip : str, key : str):
        with self.connection:
            self.cursor.execute("UPDATE Users SET ip = ? WHERE key = ?", (ip, key))

    def GetSub(self,key : str):
        with self.connection:
           if self.cursor.execute(f"SELECT sub FROM Users WHERE key = '{key.strip()}'").fetchone() is None:
               return "NONE"
           return self.cursor.execute(f"SELECT sub FROM Users WHERE key = '{key.strip()}'").fetchone()[0]

    

    def Time(self):
         print("SET TIME")
         with self.connection:
             for id in self.cursor.execute("SELECT time FROM Users").fetchall():
                column_value = id[0]
                if column_value < 1:
                    self.cursor.execute("DELETE FROM Users WHERE time = ?",(column_value,))
                    continue
                self.cursor.execute("UPDATE Users SET time = ? WHERE time = ?", (int(column_value) -1, column_value))


    

   
