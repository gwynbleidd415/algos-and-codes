from IPython.display import clear_output
from random import randint

def contin():
    a=input('Do you want to play again (y or n)?==')
    return a.lower()=='y'

print('Welcome to the game of tic tac toe...')
cont=True
while cont:
    turn = randint(0,1)
    player=['X','Y']
    b=input(f'Player {1+turn} Select X or Y->').upper()
    if player[turn]!=b:
        player=player[::-1]
    print('Just choose the position you want to select and from the given positions')
    l=[[1,2,3],[4,5,6],[7,8,9]]
    win=True
    count=0
    while(win and count<9):
        for i in l:
            print(f"{i[0]:^3} | {i[1]:^3} | {i[2]:^3}")
            print('-'*16)
        cond=0
        while not cond:
            print(f'Player {1+turn} please select your box')
            ans=int(input())
            for x in l:
                for ind,y in enumerate(x):
                    if y==ans:
                        x[ind]=player[turn]
                        cond=1
                        break
                if cond==1:
                    break
            if cond==0:
                print('Its already filled please try again')
        clear_output()
        for i in range(0,3):
            if l[i]==list(player[turn]*3) or l[0][i]==l[1][i]==l[2][i]:
                win=False
        if l[0][0]==l[1][1]==l[2][2] or l[2][0]==l[1][1]==l[0][2]:
            win=False
        if not win:
            print(f'Congrajulations Player {1+turn} has won')
            cont=contin()
        count+=1
        turn=1-turn
    if win:
        print("OPPS...It's a tie")
        cont=contin()
