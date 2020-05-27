cd /data/shared/google_travel_data
/usr/bin/wget https://www.gstatic.com/covid19/mobility/Global_Mobility_Report.csv --tries=10 --retry-connrefused --timestamping --backups=30

cd /home/uczmh2/covid/covid19-sp/data
git pull
cp /data/shared/google_travel_data/Global_Mobility_Report.csv .

cd /home/uczmh2/covid/covid19-sp/data/archive
cp /data/shared/google_travel_data/* .
rm Global_Mobility_Report.csv

cd /home/uczmh2/covid/covid19-sp/
git add data
git commit -m "auto update google data"
git push


cd /data/shared/gov_uk-data
/usr/bin/wget https://coronavirus.data.gov.uk/downloads/csv/coronavirus-cases_latest.csv --tries=10 --retry-connrefused --timestamping --backups=30
/usr/bin/wget https://coronavirus.data.gov.uk/downloads/csv/coronavirus-deaths_latest.csv --tries=10 --retry-connrefused --timestamping --backups=30

cd /home/uczmh2/covid/covid19-sp/data
git pull
cp /data/shared/gov_uk-data/coronavirus-cases_latest.csv .
cp /data/shared/gov_uk-data/coronavirus-deaths_latest.csv .

cd /home/uczmh2/covid/covid19-sp/data/archive
cp /data/shared/gov_uk-data/* .
rm coronavirus-cases_latest.csv
rm coronavirus-deaths_latest.csv

cd /home/uczmh2/covid/covid19-sp/
git add data
git commit -m "auto update gov.uk data"
git push



cd /data/shared/ons_xlsx
for year in 2020 
do
	for week in 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
	do
		wget --tries=10 --retry-connrefused --timestamping -O "ONS_spreadsheet_""$year""_week""$week"".xlsx" "https://www.ons.gov.uk/file?uri=%2fpeoplepopulationandcommunity%2fbirthsdeathsandmarriages%2fdeaths%2fdatasets%2fweeklyprovisionalfiguresondeathsregisteredinenglandandwales%2f2020/publishedweek""$week""$year".xlsx
		find . -type f -size 0 -delete

	done
done
cp `find -type f -name "\ONS*.*"  -print | tail -n 1` /home/uczmh2/covid/covid19-sp/data/ONS_spreadsheet_latest.xlsx

cd /home/uczmh2/covid/covid19-sp/
git pull
git add data
git commit -m "ons spreadsheet auto update"
git push



cd /home/uczmh2/covid/
source /home/uczmh2/covid/bin/activate
cd /home/uczmh2/covid/covid19-sp/python
git pull
python ons_download_deaths_data.py
cd ../data
git add ONS_data.csv
git add ONS_excess_deaths.csv
git commit -m "auto update ons data from API"
git push


cd /home/uczmh2/covid/
source /home/uczmh2/covid/bin/activate
cd /home/uczmh2/covid/covid19-sp/python
git pull
python  ons_process_spreadsheet.py
cd ../data
git add ONS_daily_deaths.csv
git commit -m "auto update ONS daily deaths CSV from spreadsheet"
git push
