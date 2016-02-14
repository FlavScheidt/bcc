#! /usr/bin/env python
#encoding: utf-8

import os, sys, struct

SIZE_LIMIT=40

class Field(object):
	def __init__(self,size,mines):
		self.size = size
		self.mines = mines
		self.matrix = []

	def generateField(self):
		#Reset the field and add mines
		for i in xrange(self.size):
			self.matrix.append([])
			for n in xrange(self.size):
				self.matrix[i].append(0)
		minesLeft = self.mines
		#Try a random place, if occupied, try the next one
		while minesLeft > 0:
			x = struct.unpack("I",os.urandom(4))[0] % self.size
			y = struct.unpack("I",os.urandom(4))[0] % self.size
			while self.matrix[y][x] or (x == self.size//2 and y == self.size//2):
				x += 1
				if x == self.size:
					x,y = 0,y+1
				if y == self.size:
					y = 0
			else:
				self.matrix[y][x] = 9
			minesLeft -= 1
	
	def drawField(self):
		print self.size, self.mines
		for y in xrange(self.size):
			for x in xrange(self.size):
				if self.matrix[y][x]:
					print x+1, y+1

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

	mField.generateField()
	mField.drawField()

if __name__ == "__main__":
	main(sys.argv)