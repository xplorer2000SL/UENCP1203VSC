import sys
import time
from colorama import Fore, Style, init

init(autoreset=True)

def type_effect(text, delay=0.05, color=Fore.CYAN):
    """Prints text character by character with a delay and color."""
    for char in text:
        sys.stdout.write(color + char)
        sys.stdout.flush()
        time.sleep(delay)
    print()

lyrics = [
    ("So whatever you do", 0.08, Fore.LIGHTGREEN_EX),
    ("Know that I will still be here", 0.08, Fore.CYAN),
    ("If the whole world shuts you out", 0.07, Fore.MAGENTA),
    ("I'm not gonna run", 0.1, Fore.GREEN),
    ("If you mess it up, I'll be the one", 0.05, Fore.BLACK),
    ("Be the first to let you live it down", 0.08, Fore.MAGENTA),
]

def main():
    print(Fore.LIGHTWHITE_EX + Style.BRIGHT + "\nEnjoy Atty ✨\n")
    
    for line, char_delay, color in lyrics:
        type_effect(line, delay=char_delay, color=color)
        time.sleep(0.5) 

if __name__ == "__main__":
    main()