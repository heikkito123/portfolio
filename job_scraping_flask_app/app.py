from flask import Flask, render_template, request
from utilities import get_jobs, parse_form_input

app = Flask(__name__)

@app.route('/', methods=['GET','POST'])
def index():
    jobs = {}
    #jobs_dict = get_jobs()
    if request.method == 'POST':
        alue = request.form.get('alue')
        haku = request.form.get('haku')
        jobs = get_jobs(alue, haku)

    return render_template('index.html', jobs=jobs)

if __name__ == '__main__':
    app.run(debug=True)