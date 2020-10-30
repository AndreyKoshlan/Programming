maze = [
    "####B######################",
    "# #       #   #      #    #",
    "# # # ###### #### ####### #",
    "# # # #       #   #       #",
    "#   # # ######### # ##### #",
    "# # # #   #       #     # #",
    "### ### ### ############# #",
    "# #   #     # #           #",
    "# # #   ####### ###########",
    "# # # #       # #         C",
    "# # ##### ### # # ####### #",
    "# # #     ### # #       # #",
    "#   ##### ### # ######### #",
    "######### ### #           #",
    "# ####### ### #############",
    "A           #   ###   #   #",
    "# ############# ### # # # #",
    "# ###       # # ### # # # #",
    "# ######### # # ### # # # F",
    "#       ### # #     # # # #",
    "# ######### # ##### # # # #",
    "# #######   #       #   # #",
    "# ####### ######### #######",
    "#         #########       #",
    "#######E############D######"
]

wall = ['#']
searched = ['☺']
space = [' ']
exit = list(map(chr, range(65, 91)))

def Debug(cmaze, X, Y):
	import os
	os.system("cls")
	for i in range(len(cmaze)):
		print(cmaze[i])
	print()
	print('X:', X, 'Y:', Y)
	os.system("timeout -t 0 > null")

def GetByCoord(cmaze, X, Y):
	return cmaze[Y][X]

def SetByCoord(cmaze, X, Y, Value):
	cmaze[Y] = cmaze[Y][:X] + Value + cmaze[Y][X + 1:]

def isCoordinatesCorrect(cmaze, X, Y):
	return		(X >= 0) and (Y >= 0)\
			and (X < len(cmaze[0])) and (Y < len(cmaze))\
			and (not GetByCoord(cmaze, X, Y) in wall)\
			and (not GetByCoord(cmaze, X, Y) in searched)

def getCoordinatesFromQueue(queue, i):
	return queue[i][0], queue[i][1]

def BFS(X, Y):
	cmaze = maze
	found = []
	i = 0
	queue = [[X, Y]]
	while i < len(queue):
		X, Y = getCoordinatesFromQueue(queue, i)
		i += 1
		if GetByCoord(cmaze, X, Y) in exit:
			found += [GetByCoord(cmaze, X, Y)]
			SetByCoord(cmaze, X, Y, searched[0])
			continue
		SetByCoord(cmaze, X, Y, searched[0])
		if isCoordinatesCorrect(cmaze, X+1, Y):
			queue += [[X+1, Y]]
		if isCoordinatesCorrect(cmaze, X, Y+1):
			queue += [[X, Y+1]]
		if isCoordinatesCorrect(cmaze, X-1, Y):
			queue += [[X-1, Y]]
		if isCoordinatesCorrect(cmaze, X, Y-1):
			queue += [[X, Y-1]]
	return found

X, Y = map(int, input().split())
if isCoordinatesCorrect(maze, X, Y):
	print(" ".join(BFS(X, Y)))
else:
	print('Не верные координаты')