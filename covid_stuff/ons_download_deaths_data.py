import json
from itertools import product

import requests

from lib._csv_utils import write_to_csv

SEXES = ['all', 'female', 'male']
AGEGROUPS = ['all', '0-1', '1-4', '5-9', '10-14', '15-19', '20-24', '25-29', '30-34', '35-39', '40-44',
             '45-49', '50-54', '55-59', '60-64', '65-69', '70-74', '75-79', '80-84', '85-89', '90+']
DEATH_TYPES = ['deaths-involving-covid-19-occurrences',
               'deaths-involving-covid-19-registrations', 'total-registered-deaths']
WEEKS = ['week-' + str(i) for i in range(1, 54)]


def getdata(week, sex, agegroup, death_type):
    baseurl = "https://api.beta.ons.gov.uk/v1/datasets/weekly-deaths-age-sex/editions/covid-19/versions/2/observations"
    payload = {'time': '2020', 'geography': 'K04000001', 'week': week,
               'sex': sex, 'agegroups': agegroup, 'deaths': death_type}
    r = requests.get(baseurl, params=payload)
    try:
        obj = json.loads(r.text)
    except json.decoder.JSONDecodeError:
        obj = None
    return obj


def build_csv():
    csv = []
    for week, agegroup, sex in product(WEEKS, AGEGROUPS, SEXES):
        row = {'week': week, 'agegroup': agegroup, 'sex': sex}
        data = getdata(week=week, sex=sex, agegroup=agegroup, death_type='*')
        if data is None:
            return csv
        for d in data['observations']:
            row[d['dimensions']['deaths']['id']] = d['observation']
        csv.append(row)
    return csv


def deaths_by_week(data, week):
    deaths = [d['total-registered-deaths'] for d in csv_data
              if d['sex'] == 'all' and d['agegroup'] == 'all' and d['week'] == 'week-' + str(week)]
    if len(deaths) > 0:
        return float(deaths[0])
    else:
        return ''


csv_data = build_csv()
write_to_csv(csv_data, '../data/ONS_data.csv', ['week', 'agegroup', 'sex'] + DEATH_TYPES)


# baseline from Katie Severn's ONS download
baseline = []
baseline.append({'week': 1, '2019': 10955, '2018': 12723, '2017': 11991, '2016': 13045, '2015': 12286})
baseline.append({'week': 2, '2019': 12609, '2018': 15050, '2017': 13715, '2016': 11501, '2015': 16237})
baseline.append({'week': 3, '2019': 11860, '2018': 14256, '2017': 13610, '2016': 11473, '2015': 14866})
baseline.append({'week': 4, '2019': 11740, '2018': 13935, '2017': 12877, '2016': 11317, '2015': 13934})
baseline.append({'week': 5, '2019': 11297, '2018': 13285, '2017': 12485, '2016': 11052, '2015': 12900})
baseline.append({'week': 6, '2019': 11660, '2018': 12495, '2017': 12269, '2016': 11170, '2015': 12039})
baseline.append({'week': 7, '2019': 11824, '2018': 12246, '2017': 11644, '2016': 10590, '2015': 11822})
baseline.append({'week': 8, '2019': 11295, '2018': 12142, '2017': 11794, '2016': 11056, '2015': 11434})
baseline.append({'week': 9, '2019': 11044, '2018': 10854, '2017': 11248, '2016': 11285, '2015': 11472})
baseline.append({'week': 10, '2019': 10898, '2018': 12997, '2017': 11077, '2016': 11010, '2015': 11469})
baseline.append({'week': 11, '2019': 10567, '2018': 12788, '2017': 10697, '2016': 11022, '2015': 10951})
baseline.append({'week': 12, '2019': 10402, '2018': 11913, '2017': 10325, '2016': 9635, '2015': 10568})
baseline.append({'week': 13, '2019': 9867, '2018': 9941, '2017': 10027, '2016': 10286, '2015': 10493})
baseline.append({'week': 14, '2019': 10126, '2018': 10794, '2017': 9939, '2016': 11599, '2015': 9062})
baseline.append({'week': 15, '2019': 10291, '2018': 12301, '2017': 8493, '2016': 11417, '2015': 10089})
baseline.append({'week': 16, '2019': 9025, '2018': 11223, '2017': 9644, '2016': 10925, '2015': 11639})
baseline.append({'week': 17, '2019': 10059, '2018': 10306, '2017': 10908, '2016': 10413, '2015': 10599})
baseline.append({'week': 18, '2019': 11207, '2018': 10153, '2017': 9064, '2016': 9137, '2015': 10134})
baseline.append({'week': 19, '2019': 9055, '2018': 8624, '2017': 10693, '2016': 10637, '2015': 8862})
baseline.append({'week': 20, '2019': 10272, '2018': 10141, '2017': 10288, '2016': 9953, '2015': 10290})
baseline.append({'week': 21, '2019': 10284, '2018': 9636, '2017': 10040, '2016': 9739, '2015': 10005})
baseline.append({'week': 22, '2019': 8260, '2018': 8147, '2017': 8332, '2016': 7909, '2015': 8213})
baseline.append({'week': 23, '2019': 10140, '2018': 9950, '2017': 9766, '2016': 9873, '2015': 10157})
baseline.append({'week': 24, '2019': 9445, '2018': 9343, '2017': 9367, '2016': 9386, '2015': 9548})
baseline.append({'week': 25, '2019': 9458, '2018': 9256, '2017': 9627, '2016': 9365, '2015': 9312})
baseline.append({'week': 26, '2019': 9511, '2018': 9212, '2017': 9334, '2016': 9228, '2015': 9190})
baseline.append({'week': 27, '2019': 9062, '2018': 9258, '2017': 9263, '2016': 9138, '2015': 9205})
baseline.append({'week': 28, '2019': 9179, '2018': 9293, '2017': 9376, '2016': 9388, '2015': 9015})
baseline.append({'week': 29, '2019': 9080, '2018': 9127, '2017': 9113, '2016': 9350, '2015': 8802})
baseline.append({'week': 30, '2019': 9112, '2018': 9141, '2017': 8882, '2016': 9335, '2015': 8791})
baseline.append({'week': 31, '2019': 9271, '2018': 9161, '2017': 8941, '2016': 9182, '2015': 8617})
baseline.append({'week': 32, '2019': 9122, '2018': 9319, '2017': 9038, '2016': 9172, '2015': 8862})
baseline.append({'week': 33, '2019': 9093, '2018': 8830, '2017': 9299, '2016': 9070, '2015': 9148})
baseline.append({'week': 34, '2019': 8994, '2018': 8978, '2017': 9382, '2016': 9319, '2015': 9121})
baseline.append({'week': 35, '2019': 8242, '2018': 7865, '2017': 8149, '2016': 7923, '2015': 9026})
baseline.append({'week': 36, '2019': 9695, '2018': 9445, '2017': 9497, '2016': 9399, '2015': 7878})
baseline.append({'week': 37, '2019': 9513, '2018': 9191, '2017': 9454, '2016': 9124, '2015': 9258})
baseline.append({'week': 38, '2019': 9440, '2018': 9305, '2017': 9534, '2016': 8945, '2015': 9097})
baseline.append({'week': 39, '2019': 9517, '2018': 9150, '2017': 9689, '2016': 8994, '2015': 9529})
baseline.append({'week': 40, '2019': 9799, '2018': 9503, '2017': 9778, '2016': 9291, '2015': 9410})
baseline.append({'week': 41, '2019': 9973, '2018': 9649, '2017': 9940, '2016': 9719, '2015': 9776})
baseline.append({'week': 42, '2019': 10156, '2018': 9864, '2017': 10031, '2016': 9768, '2015': 9511})
baseline.append({'week': 43, '2019': 10021, '2018': 9603, '2017': 9739, '2016': 9724, '2015': 9711})
baseline.append({'week': 44, '2019': 10164, '2018': 9529, '2017': 9984, '2016': 10152, '2015': 9618})
baseline.append({'week': 45, '2019': 10697, '2018': 10151, '2017': 10346, '2016': 10470, '2015': 9994})
baseline.append({'week': 46, '2019': 10650, '2018': 10193, '2017': 10275, '2016': 10694, '2015': 9938})
baseline.append({'week': 47, '2019': 10882, '2018': 9957, '2017': 10621, '2016': 10603, '2015': 9830})
baseline.append({'week': 48, '2019': 10958, '2018': 10033, '2017': 10538, '2016': 10439, '2015': 9822})
baseline.append({'week': 49, '2019': 10816, '2018': 10287, '2017': 10781, '2016': 11223, '2015': 10365})
baseline.append({'week': 50, '2019': 11188, '2018': 10550, '2017': 11217, '2016': 10533, '2015': 10269})
baseline.append({'week': 51, '2019': 11926, '2018': 11116, '2017': 12517, '2016': 11493, '2015': 10689})
baseline.append({'week': 52, '2019': 7533, '2018': 7131, '2017': 8487, '2016': 8003, '2015': 8630})
baseline.append({'week': 53, '2019': '', '2018': '', '2017': '', '2016': '', '2015': 7524})

for d in baseline:
    d['2020'] = deaths_by_week(csv_data, d['week'])
    d['5_year_average'] = ''
    d['excess_deaths'] = ''
    historic = (d['2019'], d['2018'], d['2017'], d['2016'], d['2015'])
    if '' not in historic:
        d['5_year_average'] = sum(historic) / len(historic)
    if d['2020'] != '' and d['5_year_average'] != '':
        d['excess_deaths'] = d['2020'] - d['5_year_average']


write_to_csv(
    baseline, '../data/ONS_excess_deaths.csv',
    ['week', 'excess_deaths', '2020', '5_year_average', '2019', '2018', '2017', '2016', '2015'])
