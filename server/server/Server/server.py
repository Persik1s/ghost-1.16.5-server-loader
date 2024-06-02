import socket
from DataBase.dataBase import * 
from Server.settingsServer import *
from Server.Utils.crypt import encode
from discord_webhook import *

dbUsers = DataBase("D:/Server/users.db")

#HOOK DISCORD WEBHOOK
discordWeb = DiscordWebhook("")
class HttpServer:
    def __init__(self,IP,PORT) -> None:
        self.port = PORT
        self.ip = IP
        
        self.server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    
    def Run(self) -> None:
        self.server.bind((self.ip,self.port))
        self.server.listen(10)
    
        while True:
            try:
                user,addres = self.server.accept()
                print(user)
                content = self.GetRespone(user)
                self.HandlerPost(content,user,addres[0])
                user.close()
                
            except:
                continue



    def GetRespone(self,user : socket) -> str:
        content = user.recv(120).decode('utf-8')
        content = content[content.find("/") + 1:content.find("HTTP/1")]
        return content
    
    def HandlerPost(self,content : str, socket_clinet : socket, addres: str):
        if("hwid" in  content):
            hwid  = content[5:len(content)]
            boolRespone = dbUsers.ExecuteHwid(hwid)
            
            socket_clinet.send((html).encode('utf-8') + encode(boolRespone).encode('utf-8'))
            return 1
        
        elif("status" in content):
            hwid = content[7:len(content)]
            boolRespone = dbUsers.IsBaned(hwid)
            boolResponeIP = dbUsers.IsBannedIP(addres)

        
            if(("TRUE" in boolRespone)
                or 
                ("TRUE" in boolResponeIP)):
                embed = DiscordEmbed("**КАКОЙ ТО ЗАБАНЕНЫЙ ЛАПУХ ПРОБУЕТ ЗАЙТИ XD**",
                    f"IP ADDRES: {addres}\n HWID: {hwid}")
                
                discordWeb.add_embed(embed=embed)
                discordWeb.execute() 
                 
                socket_clinet.send((html).encode('utf-8') + encode("TRUE").encode('utf-8'))
                
                return 1
            
            socket_clinet.send((html).encode('utf-8') + encode("FALSE").encode('utf-8'))

            return 1
        elif("key" in  content):
            _content = content[4:len(content)] 

            _key = _content[0:_content.find('/')]
            _hwid =  _content[_content.find('/') + 1: len(content)]

            responeKey = dbUsers.IsCheckKey(_key,_hwid,addres)

            if("False" in str(responeKey) or "ERROR" in str(responeKey)):
                embed = DiscordEmbed("**ПОПЫТКА ВХОДА**",
                                    f"IP ADDRES: {addres}\nHWID: {_hwid}")
                
                discordWeb.add_embed(embed=embed)
                discordWeb.execute() 
                socket_clinet.send((html).encode('utf-8') + encode(str(responeKey)).encode('utf-8'))
                return 1
            
            embed = DiscordEmbed("**ВХОД**",
                                        f"IP ADDRES: {addres}\nHWID: {_hwid}")
                    
            discordWeb.add_embed(embed=embed)
            discordWeb.execute() 
            socket_clinet.send((html).encode('utf-8') + encode(str("ENTRANCE")).encode('utf-8'))
            
            return 1
        elif("dll" in content):
            _content = content[4:len(content)]
            #print(_content)
            _sub = dbUsers.GetSub(_content)            
            print(_sub)
            if("NONE" in _sub or "None" in _sub):
                socket_clinet.send((html).encode('utf-8') + encode(_sub).encode('utf-8'))
                return 0
            
            if("GHOST" in _sub):
                with open("dll/binary.c","r") as binary:
                    print("SEND DLL")
                    socket_clinet.send((html).encode('utf-8') + (binary.read()).encode('utf-8'))
                return 1
            return 0
           
                
        return 0
       

server = HttpServer(IP="127.0.0.1",PORT=2000)











