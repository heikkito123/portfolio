# Job Scraper Web App

A simple **Flask web application** that scrapes job listings from [Duunitori.fi](https://duunitori.fi/) and displays them in a searchable UI.  
Users can search by keyword (`haku`) and location (`alue`), and results are shown grouped by company.

---

## Features
- Scrapes job postings from Duunitori.fi  
- Flask web interface with:
  - Search by keyword (e.g. `python`)  
  - Search by area (e.g. `Helsinki, Vantaa, Espoo`)  
- Results displayed with company names and job links  
- Clean and simple UI with custom CSS  

---

## Project structure
scrape_jobs/
├── app.py # Flask app entry point
├── utilities.py # Scraping utilities
├── requirements.txt # Python dependencies
├── templates/
│ └── index.html # HTML template
├── static/
│ └── styles.css # Custom CSS
└── README.md # Project description

---

## Future improvements
Could be improved to:

- Pagination for multiple result pages
- Save/export job listings to CSV/JSON
- Add more job sources
- User authentication & favorites
- Filtering


<img width="1060" height="1239" alt="image" src="https://github.com/user-attachments/assets/978af19e-4b7b-42e5-85c6-6d75fc2ec2e4" />
