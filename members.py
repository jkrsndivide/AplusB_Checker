import codecs
import json
import urllib

def readIDs(url):
	in_bytes = urllib.urlopen(url).read()
	in_file = in_bytes.decode("utf8")
	#print (in_file)
	out_file = open('members.txt', 'w')

	temp = ''
	s = json.loads(in_file)
	for i in s:
		temp += i['login']
		temp += '\n'

	out_file.write(temp)
