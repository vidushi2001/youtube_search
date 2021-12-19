## youtube_search
fampay extern assignment

Made a project in django framework that uses youtube data api to fetch videos in reverse chronological order on the topic entered in the search bar and returns nine top videos in the form of a dashboard. 
Each of the nine card in the dashboard contains the thumbnail,title and a view button whuch redirects the user to the actual youtube video.
The api calls itself again in 10 minutes to fetch the latest videos by using the python libraries of schedule and time.


#Video card layout


![alt text](https://github.com/vidushi2001/youtube_search/blob/main/video%20card.png)

#Grid Layout

![alt text](https://github.com/vidushi2001/youtube_search/blob/main/grid%20(2).png)

#Search Bar Layout


![alt text](https://github.com/vidushi2001/youtube_search/blob/main/search%20bar%20(2).png)

#How to run?
step 1--> load the project in your preferred ide

step 2--> Install django on your terminal using the following command

                pip install django
                
step 3--> navigate to the directory of project in your terminal ,in this case it happens to be    youtube_search

                cd youtube_search
                
step 4--> run the following command:

                python manage.py runserver
                
step 5--> open the local part that shows up in the terminal i.e. http://127.0.0.1:8000/                
                
