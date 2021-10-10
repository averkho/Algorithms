# -*- coding: utf-8 -*-
"""
Created on Sun Oct  3 19:53:13 2021

@author: AVERKHO
"""

import numpy as np
import pandas as pd

import KNN_initialization_methods as init_methods

class KMeans():
    
    def __init__(self,n_clusters=3,tolerance=0.01,max_iters=100,runs=1,init_method="forgy"):
        
        self.n_clusters=3
        self.tolerance=tolerance
        self.max_iters=max_iters
        self.runs=runs
        self.init_method=init_method
        
        self.runs=runs if init_method=="forgy" else 1
    
    def fit(self,X):
        
        '''
        
        X- array of shape n x 2, where n -number of samples
        
        '''
        
        row_count,col_count=X.shape
        X_values=self.__get_values(X)
        labels=np.zeros(X.shape[0])
        costs=np.zeros(self.runs)
        all_clusterings=[]
        
        for i in range(self.runs):
            
            cluster_means=self.__initialize_means(X_values, row_count)
            
            for _ in range(self.max_iters):
                
                previous_means=np.copy(cluster_means)
                distances=self.__compute_distances(X_values,cluster_means,row_count)
                labels=self.__label_examples(distances)
                cluster_means=self.__compute_means(X_values,labels,col_count)
                
                clusters_not_changes=np.abs(cluster_means-previous_means)<self.tolerance
                
                if np.all(clusters_not_changes)!=False:
                    
                    break
                
        
        return cluster_means
    
    def __initialize_means(self,X,row_count):
        
        if self.init_method=="forgy":
            return init_methods.forgy(X,row_count,self.n_clusters)
        
    def __compute_distances(self,X,cluster_means,row_count):
        
        distances=np.zeros((X.shape[0],self.n_clusters))
        for cluster_mean_index,cluster_mean in enumerate(cluster_means):
            distances[:,cluster_mean_index]=np.linalg.norm(X-cluster_mean,axis=1)
            
        return distances
    
    def __compute_means(self,X_values,labels,col_count):
        
        cluster_means=np.zeros((self.n_clusters,col_count))
        
        for cluster_mean_index,_ in enumerate(cluster_means):
            
            cluster_elements=X[labels==cluster_mean_index]
            if len(cluster_elements):
                cluster_means[cluster_mean_index,:]=cluster_elements.mean(axis=0)
        return cluster_means
    
    def __label_examples(self,distances):
        return distances.argmin(axis=1)
        
    def __get_values(self,X):
        
        if isinstance(X,np.ndarray):
            return X
        return np.array(X)
    
    
if __name__=="__main__":

    dat=pd.read_csv('./Mall_Customers.csv')
    dat.columns
    X=dat[['Annual Income (k$)','Spending Score (1-100)']].values
    
    kMeans=KMeans()
    x=kMeans.fit(X)
    