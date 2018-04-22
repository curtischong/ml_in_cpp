#include <algorithm> // shuffle, copy
#include <iostream>  // cout
#include <iterator>  // begin, end, ostream_iterator
#include <random>    // default_random_engine, random_device
#include <vector>    // vector
#define VI vector<int>
#define PB push_back
#define MP make_pair
#define US (unsigned)
using namespace std;

void shuffle_data(vector<vector<int> > &X, vector<int> &y, int Useed=0){
    // Random shuffle of the samples in X and y
    default_random_engine eng;
    if(!Useed) eng.seed(time(0));
    else eng.seed(Useed);
    shuffle(begin(X), end(X), eng);
    shuffle(begin(y), end(y), eng);
  }
/*

def batch_iterator(X, y=None, batch_size=64):
    //Simple batch generator
    n_samples = X.shape[0]
    for i in np.arange(0, n_samples, batch_size):
        begin, end = i, min(i+batch_size, n_samples)
        if y is not None:
            yield X[begin:end], y[begin:end]
        else:
            yield X[begin:end]


def divide_on_feature(X, feature_i, threshold):
    //Divide dataset based on if sample value on feature index is larger than the given threshold
    split_func = None
    if isinstance(threshold, int) or isinstance(threshold, float):
        split_func = lambda sample: sample[feature_i] >= threshold
    else:
        split_func = lambda sample: sample[feature_i] == threshold

    X_1 = np.array([sample for sample in X if split_func(sample)])
    X_2 = np.array([sample for sample in X if not split_func(sample)])

    return np.array([X_1, X_2])


def polynomial_features(X, degree):
    n_samples, n_features = np.shape(X)

    def index_combinations():
        combs = [combinations_with_replacement(range(n_features), i) for i in range(0, degree + 1)]
        flat_combs = [item for sublist in combs for item in sublist]
        return flat_combs

    combinations = index_combinations()
    n_output_features = len(combinations)
    X_new = np.empty((n_samples, n_output_features))

    for i, index_combs in enumerate(combinations):
        X_new[:, i] = np.prod(X[:, index_combs], axis=1)

    return X_new*/

/*
def get_random_subsets(X, y, n_subsets, replacements=True):
    //Return random subsets (with replacements) of the data
    n_samples = np.shape(X)[0]
    //Concatenate x and y and do a random shuffle
    X_y = np.concatenate((X, y.reshape((1, len(y))).T), axis=1)
    np.random.shuffle(X_y)
    subsets = []

    //Uses 50% of training samples without replacements
    subsample_size = int(n_samples // 2)
    if replacements:
        subsample_size = n_samples      # 100% with replacements

    for _ in range(n_subsets):
        idx = np.random.choice(
            range(n_samples),
            size=np.shape(range(subsample_size)),
            replace=replacements)
        X = X_y[idx][:, :-1]
        y = X_y[idx][:, -1]
        subsets.append([X, y])
    return subsets*/

/*
def normalize(X, axis=-1, order=2):
    //Normalize the dataset X
    l2 = np.atleast_1d(np.linalg.norm(X, order, axis))
    l2[l2 == 0] = 1
    return X / np.expand_dims(l2, axis)


def standardize(X):
    //Standardize the dataset X
    X_std = X
    mean = X.mean(axis=0)
    std = X.std(axis=0)
    for col in range(np.shape(X)[1]):
        if std[col]:
            X_std[:, col] = (X_std[:, col] - mean[col]) / std[col]
    //X_std = (X - X.mean(axis=0)) / X.std(axis=0)
    return X_std

*/
pair<vector<VI>,pair<vector<VI>,pair<VI,VI> > > train_test_split(vector<VI> X, VI y, double train_size=0.8, bool shuffle=1, int seed=0){
    //Split the data into train and test sets
    if(shuffle){
      shuffle_data(X, y, seed);
    }
    vector<VI> X_train, X_test;
    VI y_train, y_test;
    for(int i = 0; US i <X.size();i++){
      X_train.PB(X[i]);
      y_train.PB(y[i]);
    }
    return MP(X_train,MP(X_test,MP(y_train,y_test)));
  }
/*

def k_fold_cross_validation_sets(X, y, k, shuffle=True):
    //Split the data into k sets of training / test data
    if shuffle:
        X, y = shuffle_data(X, y)

    n_samples = len(y)
    left_overs = {}
    n_left_overs = (n_samples % k)
    if n_left_overs != 0:
        left_overs["X"] = X[-n_left_overs:]
        left_overs["y"] = y[-n_left_overs:]
        X = X[:-n_left_overs]
        y = y[:-n_left_overs]

    X_split = np.split(X, k)
    y_split = np.split(y, k)
    sets = []
    for i in range(k):
        X_test, y_test = X_split[i], y_split[i]
        X_train = np.concatenate(X_split[:i] + X_split[i + 1:], axis=0)
        y_train = np.concatenate(y_split[:i] + y_split[i + 1:], axis=0)
        sets.append([X_train, X_test, y_train, y_test])

    //Add left over samples to last set as training samples
    if n_left_overs != 0:
        np.append(sets[-1][0], left_overs["X"], axis=0)
        np.append(sets[-1][2], left_overs["y"], axis=0)

    return np.array(sets)


def to_categorical(x, n_col=None):
    //One-hot encoding of nominal values
    if not n_col:
        n_col = np.amax(x) + 1
    one_hot = np.zeros((x.shape[0], n_col))
    one_hot[np.arange(x.shape[0]), x] = 1
    return one_hot


def to_nominal(x):
    //Conversion from one-hot encoding to nominal
    return np.argmax(x, axis=1)


def make_diagonal(x):
    //Converts a vector into an diagonal matrix//
    m = np.zeros((len(x), len(x)))
    for i in range(len(m[0])):
        m[i, i] = x[i]
    return m*/