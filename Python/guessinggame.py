from random import randint
ans=randint(0,100)
guess=None
prevHigh=None
noGuess=0
while guess!=ans:
    a=int(input('Enter your guessed number='))
    if(noGuess==0):
        if abs(ans-a)<=10:
            print('Warm')
        else:
            print('Cold')
        prevHigh=abs(ans-a)
        noGuess+=1
        continue
    else:
        if a==ans:
            print(f'You Won in {noGuess+1} Guesses')
            break
        if abs(ans-a)<prevHigh:
            print('Warmer')
        else:
            print('Colder')
        prevHigh=abs(ans-a)
        noGuess+=1