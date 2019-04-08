#!/usr/bin/python3

# import only required components of flask library
from flask import Flask, jsonify, request, render_template

# create a flask object
app = Flask(__name__)

# match "/" with url
# (ie. abc.com/ or abc.com/?hello=world, not abc.com/hi/hello)
@app.route("/")
def send(): # arbitrary function name
    # create dictionary of the query string (everything in url after '?')
    all_args = request.args.to_dict()

    # iterate through all keys in dictionary
    for arg in all_args:
        # get index of servo to set
        i = int(arg)
        val = int(float(all_args[arg]))
        # log for debugging
        print("servo %2.0d: %5.0d" % (i, val))
        # set the servo to the value at the key
        # [servo.set(i, val)] TODO
        
    print(type(all_args))
    # return the dictionary as json for debugging
    return render_template('index.html', servos = all_args)

# if this file is the executed file (not linked from another file)
if __name__ == "__main__":
    # run the flask server
    app.run(host='0.0.0.0', debug=True)
