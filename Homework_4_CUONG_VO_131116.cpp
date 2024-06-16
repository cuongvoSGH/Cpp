#include <ql/quantlib.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <cmath>
#include <stdio.h>
#include <Python.h>

using namespace std;

// ============================================================= //
// Dataset //


vector<pair<int, double>> parseGDPData(const string& data) {
    vector<pair<int, double>> gdpData;
    istringstream sstream(data);
    string line, year, gdp, gdp_mil;

    while (getline(sstream, line)) {
        stringstream ss(line);
        getline(ss, year, ',');
        getline(ss, gdp, ',');
        getline(ss, gdp_mil, ',');

        int gdpYear = stoi(year);
        double gdpValue = stod(gdp_mil);
        gdpData.emplace_back(gdpYear, gdpValue);
    }
    return gdpData;
}

map<int, double> createGDPTimeSeries(const vector<pair<int, double>>& data) {
    map<int, double> ts;
    for (const auto& entry : data) {
        ts[entry.first] = entry.second;
    }
    return ts;
}



double calculateMean(const map<int, double>& timeSeries) {
    double sum = accumulate(timeSeries.begin(), timeSeries.end(), 0.0,
        [](double value, const pair<int, double>& p) { return value + p.second; });
    return sum / timeSeries.size();
}

double calculateVariance(const map<int, double>& timeSeries, double mean) {
    double sum = accumulate(timeSeries.begin(), timeSeries.end(), 0.0,
        [mean](double value, const pair<int, double>& p) { return value + pow(p.second - mean, 2); });
    return sum / timeSeries.size();
}

double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}

void basicStatisticalAnalysis(const map<int, double>& gdpTimeSeries) {
    double mean = calculateMean(gdpTimeSeries);
    double variance = calculateVariance(gdpTimeSeries, mean);
    double stdDev = calculateStandardDeviation(variance);

    cout << "Mean GDP: " << mean << " million" << endl;
    cout << "Variance of GDP: " << variance << " million^2" << endl;
    cout << "Standard Deviation of GDP: " << stdDev << " million" << endl;
}


void movingAverage(const map<int, double>& gdpTimeSeries, int windowSize) {
    map<int, double> movingAverages;
    vector<double> window;
    
    for (const auto& entry : gdpTimeSeries) {
        window.push_back(entry.second);
        if (window.size() > windowSize) {
            window.erase(window.begin());
        }
        double sum = accumulate(window.begin(), window.end(), 0.0);
        movingAverages[entry.first] = sum / window.size();
    }
    
    cout << "Moving Averages:" << endl;
    for (const auto& entry : movingAverages) {
        cout << "Year: " << entry.first << ", Moving Average: " << entry.second << " million" << endl;
    }
}



vector<pair<int, double>> initDataAndParse(){
    string csvData = "1990,65977748211,65977.74821\n1991,85500935935,85500.93593\n1992,94337050693,94337.05069\n1993,96043157273,96043.15727\n1994,1.10804E+11,110803.6353\n1995,1.42294E+11,142293.781\n1996,1.60193E+11,160193.2421\n1997,1.59358E+11,159358.1785\n1998,1.74686E+11,174685.7916\n1999,1.70031E+11,170030.6621\n2000,1.7222E+11,172220.4518\n2001,1.90905E+11,190905.4935\n2002,1.9907E+11,199070.4487\n2003,2.17829E+11,217828.6611\n2004,2.55107E+11,255107.2522\n2005,3.06146E+11,306145.9448\n2006,3.44627E+11,344626.6674\n2007,4.29021E+11,429020.7554\n2008,5.336E+11,533599.7795\n2009,4.39732E+11,439731.5891\n2010,4.75697E+11,475696.6139\n2011,5.24374E+11,524374.1832\n2012,4.95231E+11,495230.5237\n2013,5.15762E+11,515761.9541\n2014,5.3908E+11,539080.4751\n2015,4.77111E+11,477111.288\n2016,4.70025E+11,470024.5596\n2017,5.24641E+11,524641.2066\n2018,5.8878E+11,588779.8508\n2019,5.96058E+11,596058.4731\n2020,5.99443E+11,599442.7836\n2021,6.81346E+11,681346.1364\n2022,6.88125E+11,688125.0105";
    
    return parseGDPData(csvData);
}

void waitForEnter() {
    cout << "Press Enter to continue...";
    cin.ignore(); // Ignore any characters in the input buffer
    cin.get();    // Wait for the user to press Enter
}

void plotGDPTimeSeries(const map<int, double>& gdpTimeSeries) {
    // Initialize Python interpreter
    Py_Initialize();

    // Import necessary Python modules
    PyObject* matplotlib = PyImport_ImportModule("matplotlib.pyplot");
    PyObject* numpy = PyImport_ImportModule("numpy");

    // Prepare data for plotting
    PyObject* xValues = PyList_New(gdpTimeSeries.size());
    PyObject* yValues = PyList_New(gdpTimeSeries.size());
    int index = 0;
    for (const auto& entry : gdpTimeSeries) {
        PyList_SetItem(xValues, index, PyLong_FromLong(entry.first));
        PyList_SetItem(yValues, index, PyFloat_FromDouble(entry.second));
        index++;
    }

    // Plot data using Matplotlib
    PyObject* plotFunc = PyObject_GetAttrString(matplotlib, "plot");
    PyObject* args = PyTuple_Pack(2, xValues, yValues);
    PyObject* result = PyObject_CallObject(plotFunc, args);

    // Save the plot to a PNG file
    PyObject* savefigFunc = PyObject_GetAttrString(matplotlib, "savefig");
    PyObject* saveargs = PyTuple_Pack(1, PyUnicode_FromString("gdp_plot.png"));
    PyObject_CallObject(savefigFunc, saveargs);

    // Clean up
    Py_XDECREF(xValues);
    Py_XDECREF(yValues);
    Py_XDECREF(plotFunc);
    Py_XDECREF(args);
    Py_XDECREF(result);
    Py_XDECREF(savefigFunc);
    Py_XDECREF(saveargs);

    // Finalize Python interpreter
    Py_Finalize();
}

int main() {

    cout << "Loading the data ........................" << endl;
    cout << endl;

    vector<pair<int, double>> gdpData = initDataAndParse();

    // Create a time series from the data
    map<int, double> gdpTimeSeries = createGDPTimeSeries(gdpData);

    cout << "GDP Time Series of Poland from 1990 to 2022:" << endl;
    for (const auto& entry : gdpTimeSeries) {
        cout << "Year: " << entry.first << ", GDP: " << entry.second << " million" << endl;
    }
    
    cout << endl;
    cout << "Loading the data completed .............." << endl;
    waitForEnter();

    cout << "Plotting the data ........................" << endl;

    plotGDPTimeSeries(gdpTimeSeries);
    cout << "Plot saved to gdp_plot.png" << endl;

    cout << "Plotting completed........................" << endl;
    cout << endl;
    waitForEnter();

    cout << "Basic Statistical Analysis" << endl;
    cout << endl;
    basicStatisticalAnalysis(gdpTimeSeries);

    cout << endl;
    waitForEnter();

    cout << "Moving Average" << endl;
    cout << endl;
    movingAverage(gdpTimeSeries, 5);

    return 0;
}
