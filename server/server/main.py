from Server.server import server,dbUsers
import schedule
import json 
from threading import Thread

def Time():
    schedule.every().day.at('21:55').do(dbUsers.Time)
    while True:
        schedule.run_pending()

def ServerF():
    server.Run()
if __name__ == "__main__":
    thread = Thread(target = Time)
    thread1 = Thread(target = ServerF)
    thread1.start()
    thread.start()
    thread.join()
    thread1.join()
    

