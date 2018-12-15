# reader.py
import time
import sys
import urllib2
old_num=0
# Enter Your API key here
myAPI = 'M4O8DJ4A39C4JRM4' 
# URL where we will send the data, Don't change it
baseURL = 'https://api.thingspeak.com/update?api_key=%s' % myAPI 
for x in range(0, 1000):
        print(x)	
	time.sleep(20)
	import fileinput
	content = []
	num_lines = sum(1 for line in open('n1.txt'))
	fileinput.close()
	#print(num_lines)
	print num_lines
	print old_num
	if num_lines == old_num:
		a=1 
	else:
		with open('n1.txt') as fp:
		    for i, line in enumerate(fp):
		        if i == old_num:		
				print line.strip()	
				tem=line.strip()
				# Formatting to two decimal places
				temp = '%.2f' % float(tem)
                                break
                with open('n1r.txt') as fp:
		    for i, line in enumerate(fp):
		        if i == old_num:		
				print line.strip()	
				rss=line.strip()
				# Formatting to two decimal places
				rssi = '%.2f' % float(rss)
				# Sending the data to thingspeak
				conn = urllib2.urlopen(baseURL + '&field1=%s&field2=%s' % (temp, rssi))
				print 111111111111111111111111111111
				old_num= old_num+1
				#print conn.read()
				# Closing the connection
				conn.close()
				break
		 
		

 

