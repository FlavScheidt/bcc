#! /usr/bin/env python
	
#encoding: utf-8

import sys

NUMBER=(" ","\033[1;34m1\033[1;m","\033[1;32m2\033[1;m","\033[1;31m3\033[1;m","\033[1;33m4\033[1;m","\033[1;36m5\033[1;m","\033[1;35m6\033[1;m","\033[1;37m7\033[1;m","\033[1;30m8\033[1;m","\033[1;41mM\033[1;m","\033[1;30m#\033[1;m")
AROUND=((0,-1),(-1,-1),(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1))
AROUND2=((0,-1),(-1,0),(0,1),(1,0))

class Field(object):
	def __init__(self):
		self.size,self.mines = map(int,raw_input().split())
		self.matrix = []
		self.revealed = []
		self.minesFlagged = 0
		self.message = ""
		self.moves = 0
		self.guesses = 0
		self.toReveal = []
		self.complex = 0
		for y in xrange(self.size):
			self.matrix.append([])
			self.revealed.append([])
			for x in xrange(self.size):
				self.matrix[y].append(0)
				self.revealed[y].append(10)
	
	def readField(self):
		for i in xrange(self.mines):
			x,y = map(int,raw_input().split())
			x -= 1
			y -= 1
			self.matrix[y][x] = 9
		#Calculate how many mines are around it
		for y in xrange(self.size):
			for x in xrange(self.size):
				if self.matrix[y][x] is not 9:
					for i,n in AROUND:
						if x+n >= 0 and x+n < self.size and y+i >= 0 and y+i < self.size and self.matrix[y+i][x+n] == 9:
							self.matrix[y][x] += 1

	def reveal(self,y,x):
		toReturn = False
		#Bomb
		if self.matrix[y][x] == 9:
			self.message += " \033[1;31mI lost!\033[1;m"
			toReturn = True
		#Number
		elif self.matrix[y][x] > 0:
			self.revealed[y][x] = self.matrix[y][x]
		#Empty
		else:
			for i,n in AROUND:
				if x+n >= 0 and x+n < self.size and y+i >= 0 and y+i < self.size and self.matrix[y+i][x+n] is not 9:
					self.toReveal.append((y+i,x+n))
		self.revealed[y][x] = self.matrix[y][x]
		return toReturn

	def drawField(self):
		print
		print self.message
		print self.minesFlagged, "of", self.mines
		print self.moves, "moves /", self.complex, "complex"
		print self.guesses, "guesses"
		for y in xrange(self.size):
			line = ""
			for x in xrange(self.size):
				line += NUMBER[self.revealed[y][x]]
			print line
	
	def drawField2(self):
		print
		for y in xrange(self.size):
			line = ""
			for x in xrange(self.size):
				line += NUMBER[self.matrix[y][x]]
			print line
	
	def revealList(self):
		while len(self.toReveal) > 0:
			#Only reveal if it hasn't been revealed already
			if self.revealed[self.toReveal[0][0]][self.toReveal[0][1]] in (9,10):
				if self.reveal(*self.toReveal[0]):
					self.toReveal.pop(0)
					return True
			self.toReveal.pop(0)
		return False

	def getFlagged(self,y,x):
		toReturn = 0
		for i,n in AROUND:
			if x+n in xrange(self.size) and y+i in xrange(self.size) and self.revealed[y+i][x+n] == 9:
				toReturn += 1
		return toReturn

	def getUnrevealed(self,y,x):
		toReturn = 0
		for i,n in AROUND:
			if x+n in xrange(self.size) and y+i in xrange(self.size) and self.revealed[y+i][x+n] == 10:
				toReturn += 1
		return toReturn

	def flagMine(self,y,x):
		if x not in xrange(self.size) or y not in xrange(self.size) or self.revealed[y][x] < 10:
			return False
		self.revealed[y][x] = 9 
		self.minesFlagged += 1
		return True

	def play(self):
		#Check for victory
		if self.minesFlagged == self.mines:
			self.verifyVictory()
			return True
		self.moves += 1
		self.message = "Not a guess"
		#First move is always a guess
		if self.moves == 1:
			self.message = "Guess"
			self.guesses += 1
			return self.reveal(self.size//2, self.size//2)
		#Most simple play
		for y in xrange(self.size):
			for x in xrange(self.size):
				if self.revealed[y][x] in xrange(1,9) and self.getUnrevealed(y,x) and self.revealed[y][x] == self.getUnrevealed(y,x) + self.getFlagged(y,x):
					moves = -1
					for i,n in AROUND:
						if x+n >= 0 and x+n < self.size and y+i >= 0 and y+i < self.size and self.revealed[y+i][x+n] == 10:
							self.flagMine(y+i,x+n)
							moves += 1
					self.moves += moves
					return False
		#Reveal more spots
		moves = 0
		for y in xrange(self.size):
			for x in xrange(self.size):
				if self.revealed[y][x] in xrange(1,9) and self.revealed[y][x] == self.getFlagged(y,x):
					for i,n in AROUND:
						if x+n >= 0 and x+n < self.size and y+i >= 0 and y+i < self.size and self.revealed[y+i][x+n] == 10:
							self.toReveal.append((y+i,x+n))
							moves += 1
		if moves:
			self.moves += moves - 1
		if len(self.toReveal) > 0:
			return self.revealList()
					
		#Most complex play, involving more than one number
		for y in xrange(self.size):
			for x in xrange(self.size):
				x0,y0,x1,y1,x2,y2 = self.complexCandidate(y,x)
				if x0 or y0 or x1:
					moves = -1
					if self.flagMine(y1,x1):
						moves += 1
					if self.flagMine(y2,x2):
						moves += 1
					self.moves += moves
					self.complex += 1 + moves
					return False
		#And, finally, guess
		self.message = "Guess"
		self.guesses += 1
		#Find a place where there probably isn't a mine
		gx = 0;
		gy = 0;
		chance = 100.0;
		for y in xrange(self.size):
			for x in xrange(self.size):
				if self.revealed[y][x] == 10 and self.chanceOfBomb(y,x) < chance:
					chance = self.chanceOfBomb(y,x)
					gx = x
					gy = y
		return self.reveal(gy,gx)
	
	def placesAround(self,y,x):
		counter = 0
		for i,n in AROUND:
			if y+i in xrange(self.size) and x+n in xrange(self.size):
				counter += 1
		return counter
				

	def chanceOfBomb(self, y, x):
		chance = 0
		for i,n in AROUND:
			if y+i in xrange(self.size) and x+n in xrange(self.size) and self.revealed[y+i][x+n] != 9:
				if self.revealed[y+i][x+n] < 9:
					chance += ((self.getUnrevealed(y+i,x+n) - self.revealed[y+i][x+n] + self.getFlagged(y+i,x+n)) / self.placesAround(y,x)) * 8
				else:
					# 3 sounds good
					chance += 3
		return chance

	def verifyVictory(self):
		self.message = "\033[1;32mI won!\033[1;m"
		for y in xrange(self.size):
			for x in xrange(self.size):
				if self.revealed[y][x] == 9 and self.matrix[y][x] != 9:
					self.message = "\033[1;31mI thought I had won, but I lost!\033[1;m"
					return
	
	def complexCandidate(self, y, x):
		target = self.getUnrevealed(y,x) - self.revealed[y][x] + self.getFlagged(y,x)
		if target == 0 or self.getFlagged == self.revealed[y][x] or target >= self.revealed[y][x] - self.getFlagged(y,x):
			return 0,0,0,0,0,0
		relative = 0
		for i,n in AROUND2:
			if x+n in xrange(self.size) and y+i in xrange(self.size) and self.revealed[y+i][x+n] > target and self.revealed[y+i][x+n] < 9:
				return 0,0,0,0,0,0
		for i,n in AROUND2:
			if x+n in xrange(self.size) and y+i in xrange(self.size) and self.revealed[y+i][x+n] == target and x-n in xrange(self.size) and y-i in xrange(self.size) and self.revealed[y-i][x-n] <= target:
				x1 = x+n
				y1 = y+i
				x2 = x+n
				y2 = y+i
				if relative in (0,2):
					y1 -= 1
					y2 += 1
				else:
					x1 -= 1
					x2 += 1
				if (y1 in xrange(self.size) and x1 in xrange(self.size) and self.revealed[y1][x1] == 10) or (y2 in xrange(self.size) and x2 in xrange(self.size) and self.revealed[y2][x2] == 10):
					return x+n, y+i, x1, y1, x2, y2
			relative += 1
		return 0,0,0,0,0,0

def main(argv=None):
	verbose = False
	try:
		if argv[1] == "-v":
			verbose = True
	except IndexError:
		pass
	mField = Field()
	mField.readField()
	while not mField.play():
		if verbose: mField.drawField()
	if verbose:
		mField.drawField()
		mField.drawField2()
	else:
		print mField.message
		print mField.moves, "moves /", mField.complex, "complex"
		print mField.guesses, "guesses"

if __name__ == "__main__":
	main(sys.argv)
