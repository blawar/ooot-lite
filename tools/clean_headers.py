#!/usr/bin/python3

import os.path
from pathlib import Path
import sys

magic = '// GENERATED'
includeHeader = '#include "asset_common.h"'
removeHeaders = ['#include "z64animation.h"', '#include "z64bgcheck.h"', '#include "asset_common.h"',
									'#include "z64.h"', '#include "macros.h"']

noLuts = ['gameplay_keep', 'gameplay_dangeon', 'gameplay_field']

def writeFile(path, buffer):
	with open(path, 'r') as f:
		if f.read() == buffer:
			return

	print('writing %s' % path)
	with open(path, 'w') as f:
		f.write(buffer)

def clean(buffer):
	lines = []
	for line in buffer.split('\n'):
		line = line.replace('\r', '').strip()

		if len(line) == 0:
			continue

		if line.startswith('static void*') or line.startswith(magic):
			break

		lines.append(line)

	return '\n'.join(lines)

def cleanC(buffer):
	lines = []
	for line in buffer.split('\n'):
		line = line.replace('\r', '').strip()

		if line.startswith(magic):
			break

		lines.append(line)

	return '\n'.join(lines)

dir = 'assets/'
files = []
search = []

if len(sys.argv) > 1:
	for x in sys.argv[1:]:
		search.append(x.replace('\\', '/'))

for path in Path(dir).rglob('*.h'):
	x = str(path).replace('\\', '/')

	if len(search):
		for s in search:
			if s in x:
				files.append(path)
				break
	else:
		files.append(path)

for path in files:
	x = str(path).replace('\\', '/')
	skip = False

	if '/text/' in x:
		continue

	if '/overlays/' in x:
		skip = True

	name = path.name[0:-2]
	c_path = str(path)[0:-2] + '.c'

	with open(path, 'r') as f:
		buffer = clean(f.read())

	result = '#pragma once\n'
	result += buffer

	if skip:
		with open(c_path, 'r') as f:
			resultC = buffer = f.read()
	else:
		with open(c_path, 'r') as f:
			buffer = cleanC(f.read()).strip()
			resultC = buffer

	for i in removeHeaders:
		resultC = resultC.replace(i + '\n', '')

	if includeHeader not in resultC:
		resultC = resultC.replace('#include "ultra64.h"', includeHeader)

	if '_scene.c' in c_path:
		resultC = resultC.replace('#include "z64cutscene.h"', '')
		resultC = resultC.replace('#include "ultra64.h"', '#include "ultra64.h"\n' + '#include "z64cutscene.h"')

	writeFile(path, result)
	writeFile(c_path, resultC)