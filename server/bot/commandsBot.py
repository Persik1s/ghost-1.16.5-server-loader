from discord.ext import commands
from discord.ui import Button, View,Select
from discord.utils import get
from dataBase import DataBase
from yoomoney import *
import random
import discord
import json

bot = commands.Bot(command_prefix='/',intents=discord.Intents.all())
dataBase = DataBase("D:/Server/users")

TOKEN_YOU_MONEY = ''
client = Client(TOKEN_YOU_MONEY)

priceMinecraft = [120,250,500]


labelNmae = ["OSPW GHOST[1]","OSPW GHOST[7]","OSPW GHOST[30]"]

channleID = 1240524029652107284
guildID =  1237394769429270589


roleGHOST = 1240524106198421595





@bot.command()
async def buy(ctx):
    select = discord.ui.Select(options=[
        discord.SelectOption(label=labelNmae[0], description=f"Minecraft 1.16.5 | 1 days\n {priceMinecraft[0]}₽"),
        discord.SelectOption(label=labelNmae[1], description=f"Minecraft 1.16.5 | 7 days\n {priceMinecraft[1]}₽"),
        discord.SelectOption(label=labelNmae[2], description=f"Minecraft 1.16.5 | 30 days\n {priceMinecraft[2]}₽")
    ],min_values=1,max_values=1)
    

    author = ctx.message.author
  
    async def callback(interaction):
        if select.values[0] == labelNmae[0]:
            bill = random.randint(0,20000)
            dataBase.InitBuyBill(ctx.author.id,bill)

            quik =  Quickpay(label=bill,sum=priceMinecraft[0],receiver="4100118441539491",targets="OSPW",quickpay_form="shop",paymentType="SB")
            embed = discord.Embed(title=select.values[0],description=quik.base_url)
            dataBase.InitBuySubscription(ctx.author.id,select.values[0])
            await interaction.response.send_message(embed = embed)

            
           
        elif select.values[0] == labelNmae[1]:
            bill = random.randint(0,20000)
            dataBase.InitBuyBill(ctx.author.id,bill)

            quik =  Quickpay(label=bill,sum=priceMinecraft[1],receiver="4100118441539491",targets="OSPW",quickpay_form="shop",paymentType="SB")
            embed = discord.Embed(title=select.values[0],description=quik.base_url)
            dataBase.InitBuySubscription(ctx.author.id,select.values[0])
            await interaction.response.send_message(embed = embed)
         
           

        elif select.values[0] == labelNmae[2]:
            bill = random.randint(0,20000)
            dataBase.InitBuyBill(ctx.author.id,bill)


            quik =  Quickpay(label=bill,sum=priceMinecraft[2],receiver="4100118441539491",targets="OSPW",quickpay_form="shop",paymentType="SB")
            embed = discord.Embed(title=select.values[0],description=quik.base_url)
            dataBase.InitBuySubscription(ctx.author.id,select.values[0])
            await interaction.response.send_message(embed = embed)
          
        select.disabled = True
        
    select.callback =callback

    viwe = View()
    viwe.add_item(select)
    await author.send("", view=viwe)
    
    

    
@bot.command()
async def check(ctx):
    bill = dataBase.SelectBill(ctx.author.id)
    history = client.operation_history(label=bill)

    for operation in history.operations:
        if operation.status == "success": 
            time = None
            if str("1").strip() in dataBase.SelectBuySubscription(ctx.author.id):
                 time = "1"
            if str("7").strip() in dataBase.SelectBuySubscription(ctx.author.id):
                time = "7"
            if str("30").strip() in dataBase.SelectBuySubscription(ctx.author.id):
                time = "30"

            key = None
            while True:
                key = "KEY_" + str(random.randint(10,20000)) + "_"+ str(random.randint(10,20000)) + "_" + str(random.randint(10,20000))
                if  dataBase.SelectKey(key):
                    continue
                break
            

            #USER ADD INFO
            dataBase.InitBuyBill(ctx.author.id,0)
           
            user = bot.get_guild(guildID).get_member(ctx.author.id)
            role = bot.get_guild(guildID).get_role(roleGHOST)

            await user.add_roles(role)            
            
          
            channle = bot.get_channel(channleID)

            embedChannle = discord.Embed(title="ВОУ ВОУ ЩИТ",description=f"\n Key:{key}\n Оплатил: <@{ctx.author.id}>\n Подписка: `{dataBase.SelectBuySubscription(ctx.author.id)}`\n Сумма: {operation.amount}")
            await channle.send(embed=embedChannle)
            
         

            dataBase.InitKey(key)
            dataBase.InitUsersSubscription(key, dataBase.SelectBuySubscription(ctx.author.id))
            dataBase.InitStatus(key,"FALSE")
            dataBase.InitTime(key,time)
   




