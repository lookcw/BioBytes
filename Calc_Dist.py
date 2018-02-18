from math import cos, asin, sqrt
import sys
def distance(lat1, lon1, lat2, lon2):
	p = 0.017453292519943295 #Pi/180
	a = 0.5 - cos((lat2 - lat1) * p)/2 + cos(lat1 * p) * cos(lat2 * p) * (1 - cos((lon2 - lon1) * p)) / 2
	return 12742 * asin(sqrt(a)) #2*R*asin...
par = open("par_lat_lon.txt",'r')
child = open("chi_lat_lon.txt",'r')
p_loc = par.readline().split(',')
c_loc = child.readline().split(',')

dist_file = open("distance.txt",'w')
dist_file.write(distance(int(p_loc[0]),int(p_loc[1]),int(c_loc[0]),int(c_loc[1])))

