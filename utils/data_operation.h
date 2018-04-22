//#ifndef data_operation
//#define data_operation
#include <algorithm> // shuffle, copy
#include <vector>
#include <set>
#include <map>
#include <math.h>
#define VI vector<int>
#define PII pair<int,int>
#define F first
#define S second
using namespace std;

double calculate_entropy(VI y){
    //Calculate the entropy of label array y
    set<int> unique_labels(y.begin(),y.end());
    map<int,int> counts;
    for(int i : y){
      if(counts.find(i) != counts.end()){
        counts[i] =1;
      }else{
        counts[i] +=1;
      }
    }
    double entropy = 0;
    for(PII cur : counts){
      double p = cur.S/y.size();
      entropy += -p * log2(p);
    }
    return entropy;
  }

/*
def mean_squared_error(y_true, y_pred):
    """ Returns the mean squared error between y_true and y_pred """
    mse = np.mean(np.power(y_true - y_pred, 2))
    return mse

*/
double calculate_variance(VI X){
  //assuming I'm receiving an array
  //Return the variance of the features in dataset X """
  double totCount = 0;
  for(int i : X){
    totCount+=i;
  }
  double mean = totCount/X.size();
  double curTotal = 0;
  for(int i : X){
    curTotal+=pow(i-mean,2);
  }
  return curTotal/X.size();
}

double calculate_variance(vector<VI> X){
  //assuming I'm receiving an array
  //Return the variance of the features in dataset X """
  double mean = np.ones(np.shape(X)) * X.mean(0)
  n_samples = np.shape(X)[0]
  variance = (1 / n_samples) * np.diag((X - mean).T.dot(X - mean))

  return variance
}

/*
def calculate_std_dev(X):
    """ Calculate the standard deviations of the features in dataset X """
    std_dev = np.sqrt(calculate_variance(X))
    return std_dev*/


    /*double euclidean_distance(int x1, int x2){
      //Calculates the l2 distance between two vectors
      double distance = 0;
      //Squared distance between each coordinate
      for(int i = 0; i < x1.size();i++){
        distance += pow((x1[i] - x2[i]), 2)
      }
      return math.sqrt(distance)
    }*/

/*
def accuracy_score(y_true, y_pred):
    """ Compare y_true to y_pred and return the accuracy """
    accuracy = np.sum(y_true == y_pred, axis=0) / len(y_true)
    return accuracy


def calculate_covariance_matrix(X, Y=None):
    """ Calculate the covariance matrix for the dataset X """
    if Y is None:
        Y = X
    n_samples = np.shape(X)[0]
    covariance_matrix = (1 / (n_samples-1)) * (X - X.mean(axis=0)).T.dot(Y - Y.mean(axis=0))

    return np.array(covariance_matrix, dtype=float)


def calculate_correlation_matrix(X, Y=None):
    """ Calculate the correlation matrix for the dataset X """
    if Y is None:
        Y = X
    n_samples = np.shape(X)[0]
    covariance = (1 / n_samples) * (X - X.mean(0)).T.dot(Y - Y.mean(0))
    std_dev_X = np.expand_dims(calculate_std_dev(X), 1)
    std_dev_y = np.expand_dims(calculate_std_dev(Y), 1)
    correlation_matrix = np.divide(covariance, std_dev_X.dot(std_dev_y.T))

    return np.array(correlation_matrix, dtype=float)
*/
//#endif
