# -*- coding: utf-8 -*-
"""
Created on Sun Oct 10 17:48:47 2021

@author: AVERKHO
"""

import numpy as np
import matplotlib.pyplot as plt
plt.close('all')

import torch

import torch.nn as nn

rnn=nn.LSTM(5,1,1,bias=False)

input_ = torch.randn(5, 5, 1)
h0 = torch.randn(1, 5, 1)
c0 = torch.randn(1, 5, 1)

input_copy=np.squeeze(input_.cpu().detach().numpy())
input_copy=input_.cpu().detach().numpy()
output,(hn,cn)=rnn(input_,(h0,c0))

output=output.detach().numpy()

def sigmoid(x):
    
    return 1/(1+np.exp(-x))

weights=rnn.num_weights

rnn._flat_weights 

for weight in rnn._all_weights:
    print(weight)