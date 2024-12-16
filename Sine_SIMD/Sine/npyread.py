# -*- coding: utf-8 -*-
"""
Created on Wed Jul 15 13:08:27 2020

@author: Admin
"""

import numpy as np
data_array1 = np.load('E:/Research/Yantra_Contract/TensorflowLite/Sine/models/FC1_W.npy')
data_array2 = np.load('E:/Research/Yantra_Contract/TensorflowLite/Sine/models/FC1_B.npy')
data_array3 = np.load('E:/Research/Yantra_Contract/TensorflowLite/Sine/models/FC1_W_Q.npy')
data_array4 = np.load('E:/Research/Yantra_Contract/TensorflowLite/Sine/models/FC1_B_Q32.npy')
a=np.max(data_array1)
aa=np.min(data_array1)

b=np.max(data_array2)
bb=np.min(data_array2)