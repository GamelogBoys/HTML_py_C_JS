import random

while True:
    query = input("You: ").strip()
    
    if query.endswith('?'):
        prompt = [
            f"AI: {query} cannot be done",
            f"AI: Under development(Beta 2.0)"
            ]
        prompts = random.choice(prompt)
        print (prompts)
    
    elif query.startswith('Hi')or query.startswith('Hello'):
        prompt = [
            f"AI: How are you?",
            f"AI: Hello, how can I assist you today",
            f"AI: Welcome to Master Integration AI"
            ]
        prompts = random.choice(prompt)
        print (prompts)
    
    elif query == "stop" or query == "quit" or query == "Exit":
        prompt = [
            f"AI: {query}, Thanks",
            f"AI: Stopping",
            f"AI: Thanks for using MI AI"
            ]
        prompts = random.choice(prompt)
        print(prompts)
        break

    elif query == "Maths" or query == "maths":
        while True:
            choice = str(input("AI: Wany to quit maths sec Y/N:"))
            a = float(input("Enter 1st number:"))
            b = str(input("Enter the operator:"))
            c = float(input("Enter 2nd number:"))
        
            if b == "+":
                print("AI: Answer is", a+c)
            elif b == "-":
                print("AI: Answer is", a-c)
            elif b == "*":
                print("AI: Answer is", a*c)
            elif b == "/":
                print("AI: Answer is", a/c)
            elif choice == "Y":
                print("AI: Going to normal section")
                break
            else:
                print("AI: Invalid credentials")
    else:
        print("AI: Invalid credentials")