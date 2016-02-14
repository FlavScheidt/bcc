#! /usr/bin/env python
#encoding: utf-8

# fhbz10@macalan:~$ grep -i pascal trab_1.txt | wc -l
# 0

import sys
import os
import random

SIZE_LIMIT=40
NUMBER=(" ","\033[1;34m1\033[1;m","\033[1;32m2\033[1;m","\033[1;31m3\033[1;m","\033[1;33m4\033[1;m","\033[1;36m5\033[1;m","\033[1;35m6\033[1;m","\033[1;37m7\033[1;m","\033[1;30m8\033[1;m","\033[1;41mM\033[1;m","\033[1;30m#\033[1;m")
MENU=("	Menu:","		[N] New Game","		[S] Sweep Spot","		[F] Flag Mine","		[R] Reveal Field","		[Q] Quit","	Flávio Zavan GRR20101924")
AROUND=((0,-1),(-1,-1),(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1))

class Field(object):
	def __init__(self,size,mines):
		self.size = size
		self.mines = mines
		self.matrix = []
		self.revealed = []
		self.minesFlagged = 0
		self.notRevealed = self.size ** 2
		self.toReveal = []
		self.message = ""

	def drawField(self):
		os.system("clear")
		#Text
		print "Total mines:", self.mines
		print "Flagged mines:", self.minesFlagged
		print
		#Top numbers
		line = "    "
		for i in xrange(self.size):
			line += str((i+1)/10)
		print line
		line = "    "
		for i in xrange(self.size):
			line += str((i+1)%10)
		print line
		#Top border
		line = "   +"
		for i in xrange(self.size):
			line += "-"
		line += "+"
		print line
		#Field itself
		for y in xrange(self.size):
			line = "%02d |" % (y+1)
			for x in xrange(self.size):
				line += str(self.revealed[y][x])
			line += "|"
			line += " %02d" % (y+1)
			#Menu
			if y >= 0 and y < 7:
				line += MENU[y]
			elif y == 7:
				line += "	" + self.message
			print line
		#Bottom border
		line = "   +"
		for i in xrange(self.size):
			line += "-"
		line += "+"
		print line
		#Bottom numbers
		line = "    "
		for i in xrange(self.size):
			line += str((i+1)/10)
		print line
		line = "    "
		for i in xrange(self.size):
			line += str((i+1)%10)
		print line
		#Reset the message
		self.message = ""
		print
	
	def revealField(self):
		for y in xrange(self.size):
			for x in xrange(self.size):
				self.revealed[y][x] = NUMBER[self.matrix[y][x]]
		

	def revealSpot(self,y=None,x=None):
		if y is None and x is None:
			y,x = self.getXorY("Y"),self.getXorY("X")
		if self.revealed[y][x] == NUMBER[9] or self.revealed[y][x] == NUMBER[10]:
			#Update the flaggedMines counter
			if self.revealed[y][x] == NUMBER[9]:
				self.minesFlagged -= 1
			#Bomb
			if self.matrix[y][x] == 9:
				self.revealField()
				self.message = "\033[1;31mYou lost!\033[1;m"
				return True
			#Number
			elif self.matrix[y][x] > 0:
				self.revealed[y][x] = NUMBER[self.matrix[y][x]]
			#Empty
			else:
				for i,n in AROUND:
					if x+n >= 0 and x+n < self.size and y+i >= 0 and y+i < self.size and self.matrix[y+i][x+n] is not 9:
						self.toReveal.append((y+i,x+n))
			self.revealed[y][x] = NUMBER[self.matrix[y][x]]
			self.notRevealed -= 1
		else:
			self.message = "Spot already revelead."
		return False

	#Victory by revealing everything
	def checkVictory(self):
		if self.notRevealed == self.mines:
			self.revealField()
			self.message = "\033[1;32mYou won!\033[1;m"
			return True
		return False
	
	#Victory by flagging all mines
	def checkVictory2(self):
		correctFlags = 0
		for y in xrange(self.size):
			for x in xrange(self.size):
				if self.revealed[y][x] == NUMBER[9] and self.revealed[y][x] == NUMBER[self.matrix[y][x]]:
					correctFlags += 1
		if correctFlags == self.mines:
			self.message = "\033[1;32mYou won!\033[1;m"
			return True
		return False
		

	def revealList(self):
		while len(self.toReveal) > 0:
			#Only reveal if it hasn't been revealed already
			if self.revealed[self.toReveal[0][0]][self.toReveal[0][1]] in (NUMBER[9],NUMBER[10]):
				self.revealSpot(*self.toReveal[0])
			self.toReveal.pop(0)

	def getXorY(self,string):
		y = 0
		while not y:
			try:
				y = int(raw_input("%s: " % string))
				if y > self.size or y < 1:
					print "The value has to be between 1 and %d." % self.size
					y = 0
			except ValueError:
				print "Invalid number."
			except (KeyboardInterrupt,EOFError):
				print
				sys.exit()
		return y-1

	def flagMine(self):
		y,x = self.getXorY("Y"),self.getXorY("X")
		#Check if flaggable
		if self.revealed[y][x] == NUMBER[9]:
			self.revealed[y][x] = NUMBER[10]
			self.minesFlagged -= 1
		elif self.revealed[y][x] == NUMBER[10]:
			self.revealed[y][x] = NUMBER[9] 
			self.minesFlagged += 1
		else:
			self.message = "Spot already revealed."

	def readInput(self):
		try:
			entrada = raw_input("Command: ")
			entrada = entrada.upper()
			if entrada == "N":
				return True
			elif entrada == "S":
				toReturn = self.revealSpot()
				self.revealList()
				if not toReturn:
					return self.checkVictory()
				return toReturn
			elif entrada == "F":
				self.flagMine()
				return self.checkVictory2()
			elif entrada == "R":
				self.revealField()
				return True
			elif entrada == "Q":
				sys.exit()
			else:
				self.message = "Invalid command."
				return False

		except (KeyboardInterrupt,EOFError):
			print
			sys.exit()	

	def generateField(self):
		#Reset the field and add mines
		for i in xrange(self.size):
			self.matrix.append([])
			for n in xrange(self.size):
				self.matrix[i].append(0)
		#Reset the revelead field
		for i in xrange(self.size):
			self.revealed.append([])
			for n in xrange(self.size):
				self.revealed[i].append(NUMBER[10])
		minesLeft = self.mines
		random.seed()
		#Try a random place, if occupied, try the next one
		while minesLeft > 0:
			x = random.randint(0,self.size-1)
			y = random.randint(0,self.size-1)
			while self.matrix[y][x]:
				x += 1
				if x == self.size:
					x,y = 0,y+1
				if y == self.size:
					y = 0
			else:
				self.matrix[y][x] = 9
			minesLeft -= 1
		#Calculate how many mines are around it
		for y in xrange(self.size):
			for x in xrange(self.size):
				if self.matrix[y][x] is not 9:
					for i,n in AROUND:
						if x+n >= 0 and x+n < self.size and y+i >= 0 and y+i < self.size and self.matrix[y+i][x+n] == 9:
							self.matrix[y][x] += 1

def main(argv=None):
	try:
		mField = Field(int(argv[1]),int(argv[2]))
	except (IndexError,ValueError):
		sys.exit("Use %s <size> <mines>" % argv[0])
	
	#Check field problems
	if mField.size > SIZE_LIMIT or mField.size < 8:
		sys.exit("The field size has to be from 8 to %d." % SIZE_LIMIT)
	if mField.mines >= mField.size** 2 or mField.mines < 1:
		sys.exit("There has to be, at least, one mine and one clean spot.")

	while True:
		mField.generateField()
		mField.drawField()
		#Game loop
		while not mField.readInput():
			mField.drawField()
		#Restart
		mField.drawField()
		print "Game Over!"
		print "Press <Enter> to continue."
		raw_input()
		size = 0
		mines = 0
		#Ask for the size
		while not size:
			try:
				size = int(raw_input("Size: "))
				if size > SIZE_LIMIT or size < 8:
					print "The size of the field has to be from 8 to %d." % SIZE_LIMIT
					size = 0
			except ValueError:
				print "Invalid number."	
			except (KeyboardInterrupt,EOFError):
				print
				sys.exit()
		#Ask for the number of mines
		while not mines:
			try:
				mines = int(raw_input("Number of mines: "))
				if mines >= size**2 or mines < 1:
					print "There has to be, at least, one mine and one clean spot."
					mines = 0
			except ValueError:
				print "Invalid number."	
			except (KeyboardInterrupt,EOFError):
				print
				sys.exit()
		#Set the values
		mField = Field(size, mines)

if __name__ == "__main__":
	main(sys.argv)
