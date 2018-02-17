location = open('location.txt')

lattext = (location.readline())
arr = lattext.rstrip().split(" ")
lat = float(arr[1])

longtext = (location.readline())
arr = longtext.rstrip().split(" ")
long = float(arr[1])

wfile = open('data.txt', 'w')
wfile.write(str(lat) + ',' + str(long))

