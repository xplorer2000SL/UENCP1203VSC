import sys
from time import sleep
from rich.console import Console

console = Console()

def printSong():
    lines = [
        ("Crawling back to you", 0.1),
        ("Ever thought of calling when you've had a few", 0.1),
        ("'Cause I always do", 0.1),
        ("Maybe I'm too", 0.1),
        ("Busy being yours to fall for somebody new", 0.11),
        ("Now I've thought it through", 0.09),
        ("Crawling back to you", 0.09),
    ]
    
    delays = [0.88, 0.85, 1.2, 1.0, 1.2, 0.4, 1.0]
    colors = ["green", "cyan", "red", "yellow"]

    for i, (line, char_delay) in enumerate(lines):
        color = colors[i % len(colors)]
        
        for char in line:
            console.print(f"[{color}]{char}[/]", end='', highlight=False)
            sys.stdout.flush()
            sleep(char_delay)
        
        print()  
        sleep(delays[i])

if __name__ == "__main__":
    printSong()