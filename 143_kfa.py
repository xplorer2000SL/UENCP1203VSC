import sys
import time
from colorama import Fore, Style, init

init(autoreset=True)

def type_effect(text, delay=0.18, color=Fore.CYAN):
    for char in text:
        sys.stdout.write(color + char)
        sys.stdout.flush()
        time.sleep(delay)
    print()

lyrics = [
    ("So whatever you do", 0.16, Fore.LIGHTGREEN_EX),
    ("Know that I will still be here", 0.15, Fore.CYAN),
    ("If the whole world shuts you out", 0.11, Fore.LIGHTYELLOW_EX),
    ("I'm not gonna run", 0.11, Fore.GREEN),
    ("If you mess it up, I'll be the one", 0.11, Fore.LIGHTCYAN_EX),
    ("Be the first to let you live it down", 0.07, Fore.RED),
]
def main():
    print(Fore.LIGHTWHITE_EX + Style.BRIGHT + "\nEnjoy Atty ✨\n")
    
    for line, char_delay, color in lyrics:
        type_effect(line, delay=char_delay, color=color)
        time.sleep(0.5) 
if __name__ == "__main__":
    main()