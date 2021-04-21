def move(src,dest):
    print("Move disc from {} to {}!".format(src,dest))

# just to check our move function
def moveVia(frm,via,tar):
    move(frm,via)
    move(via,tar)

def hanoi(n,frm,via,tar):
    # n --> number of disks
    # frm --> from position
    # via --> helper position
    # tar --> target position
    if(n == 0):
        pass
    else:
        hanoi(n-1,frm,tar,via)
        move(frm,tar)
        hanoi(n-1,via,frm,tar)

hanoi(4,"A","B","C")
