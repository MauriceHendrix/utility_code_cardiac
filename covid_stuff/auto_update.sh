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


cd /home/uczmh2/covid/
source /home/uczmh2/covid/bin/activate
cd /home/uczmh2/covid/covid19-sp/python
git pull
pip uninstall nottingham_covid_modelling -y
pip install -r requirements.txt
pip install -e .
download_ons_data --output /home/uczmh2/covid/covid19-sp/data/ONS_daily_deaths.csv
cd ../data
git add ONS_daily_deaths.csv
git commit -m "auto update ons data"
git push