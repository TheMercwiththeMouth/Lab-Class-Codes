import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets
import skfuzzy as fuzz

# Load the Iris dataset
iris = datasets.load_iris()
data = iris.data

# Number of clusters
n_clusters = 3

# Fuzzy c-means algorithm
cntr, u, u0, d, jm, p, fpc = fuzz.cluster.cmeans(data.T, n_clusters, 2, error=0.005, maxiter=1000)

# Assign each data point to the cluster with the highest membership value
cluster_membership = np.argmax(u, axis=0)

# Plotting the results
fig, ax = plt.subplots()
colors = ['r', 'g', 'b']
for j in range(n_clusters):
    ax.scatter(data[cluster_membership == j, 0], data[cluster_membership == j, 1],
               c=colors[j], label=f'Cluster {j + 1}', marker='o')

ax.legend()
plt.xlabel('Sepal Length')
plt.ylabel('Sepal Width')
plt.title('Fuzzy C-Means Clustering on Iris Dataset')
plt.show()