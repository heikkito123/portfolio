# Invoice Automation and Processing

This project automates downloading and processing invoice data into a cleaned, project-tagged excel report. It solved a small company problem of not having a full
project management system and interface between different components. Invoicing still required manual handling after the script spat out the resulting excel-files,
but the finished script reduced hours upon hours of manual invoice handling, reduced invoice error rates and return rates to essentially my own typos in the sent invoices.
V0.2 -> migrate external excel files into a database and refine sript for robustness and error handling.

## DISCLAIMER
- Sample outputfiles are as of 18.8.2025 generated for portfolio display purposes
  -> TODO: update sample input and fix environment variables + static paths
- Sample input files missing as of 18.8.2025:
  -> Suppliers resided in another file, tagged with VAT information
  -> Current running list of managed invoices missing
  -> TODO: add mock suppliers list for workflow, possibly add managed invoice listing
- All credentials removed, all file paths removed
- Our invoice handling system was only for invoice settlement, not for anything else. The only way to handle invoces via EMCE for me was to
  first comment them in the system and then at certain time intervals download and handle them via excel.

## Features
- **Automation (Selenium):** Logs into a web portal, downloads invoices in Excel format  
- **Data Cleaning (pandas):**
  - Removes duplicate invoices by supplier + invoice number
  - Cleans supplier names and merges VAT information
  - Converts and formats dates and amounts
- **Fuzzy Matching (RapidFuzz):**
  - Detects mentions of "Urakka" (contract) and "Lisätyö" (extra work)
  - Matches invoices to project names with approximate string matching
- **Excel Output:** Creates a consolidated, sorted report ready for bookkeeping

## Project Structure
- `invoice_downloader.ipynb` – Automates login and downloading invoices (Selenium)  
- `invoice_processing.ipynb` – Cleans and processes invoice data with pandas  
- `data/` – Contains sample Excel files (dummy data) to demonstrate functionality  
- `requirements.txt` – Python dependencies  

## Stack
- Python, pandas, numpy  
- Selenium (automation)  
- RapidFuzz (fuzzy string matching)  
- Excel
