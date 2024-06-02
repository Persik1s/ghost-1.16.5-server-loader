from commandsBot import *



@bot.event
async def on_ready():
    print(f"BOT {bot.user.name} get started")
    
    await bot.change_presence(status=discord.Status.idle, activity=discord.Game('Ходит по вене 😬'))

# YOU MONEY BOT
client = Client(TOKEN_YOU_MONEY)
if __name__ == "__main__":
    buy
    check
    # TOKEN BOT START
    bot.run('')