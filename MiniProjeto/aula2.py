import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix , ConfusionMatrixDisplay
import matplotlib
matplotlib.use('TkAgg')




titanic = pd.read_csv('titanic_data.csv')
titanic.head(10)




titanic1 = titanic[['Pclass', 'Sex', 'Fare', 'Survived']]
titanic1['Sex'] = titanic1.Sex.replace({'male':0, 'female':1})
X = titanic1[['Pclass', 'Sex', 'Fare']]
y = titanic1['Survived']
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)
knn = KNeighborsClassifier(n_neighbors = 5)
knn.fit(X_train, y_train)
knn.score(X_train, y_train)
knn.score(X_test, y_test)
y_prep = knn.predict(X_test)

cm = confusion_matrix(y_test, y_prep)
disp = ConfusionMatrixDisplay(confusion_matrix=cm)
disp.plot()
plt.show()


print(titanic1)
