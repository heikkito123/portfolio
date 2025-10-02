import requests
from bs4 import BeautifulSoup
from collections import defaultdict
from pprint import pprint
import json
import re
from urllib.parse import quote

def get_jobs(alue, haku):
    alue, haku = parse_form_input(alue, haku)
    print(alue, haku)
    
    # defaultdict työpaikoille
    jobs_by_company = defaultdict(list)

    # requests ekasta sivusta
    content = requests.get(f'https://duunitori.fi/tyopaikat?alue={alue}&haku={haku}').text
    soup = BeautifulSoup(content, 'lxml')

    # katso kuinka monta sivua työpaikkoja on
    num_pages = int(soup.find_all('a', class_='pagination__pagenum')[-1].text)

    # työpaikka divit
    divs = soup.find_all('div', class_='grid grid--middle job-box job-box--lg')
    a = [div.a for div in divs]

    #ensimmäisen sivun työpaikat
    for i in range(len(a)):
        # duunitorin suositukset pois
        if 'gtm-recommendation' in a[i].attrs['class']:
            continue
        company = a[i]['data-company']
        position = "".join(a[i].contents)
        link = f"https://duunitori.fi{a[i]['href']}"
        if company:
            jobs_by_company[company].append([position, link])

    # seuraavien sivujen tyäpaikat
    for i in range(2, num_pages+1):
        content = requests.get(f'https://duunitori.fi/tyopaikat?alue={alue}&haku={haku}&sivu={i}').text
        soup = BeautifulSoup(content, 'lxml')
        divs = soup.find_all('div', class_='grid grid--middle job-box job-box--lg')
        a = [div.a for div in divs]

        for i in range(len(a)):
            if 'gtm-recommendation' in a[i].attrs['class']:
                continue
            company = a[i]['data-company']
            position = "".join(a[i].contents)
            link = f"https://duunitori.fi{a[i]['href']}"
            if company:
                jobs_by_company[company].append([position, link])
    return dict(jobs_by_company)

def parse_form_input(alue, haku):
    alue_params = ';'.join(re.sub(r'[^a-zöäåA-ZÖÄÅ-]', ' ', alue).split())
    haku_params = ';'.join(re.sub(r'[^a-zöäåA-ZÖÄÅ-]', ' ', haku).split())
    return quote(alue_params), quote(haku_params)
