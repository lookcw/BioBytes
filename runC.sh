while true
do 
./whereami > location.txt
python extract_lat_lon.py
sshpass -p "newdr0pl3t" scp -r data.txt root@165.227.214.211:BioBytes/chi_lat_lon.txt 
sleep 2
done
