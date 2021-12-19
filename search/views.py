import requests
from django.shortcuts import render
from django.conf import settings
import schedule
import time
# Create your views here.
# Search is a single page app --> includeing search bar and nine video cards

def index(request):
    videos = []
    if request.method == 'POST':
        # HTTP Request FOR VIDEOS
        search_url = 'https://www.googleapis.com/youtube/v3/search'
        video_url = 'https://www.googleapis.com/youtube/v3/videos'
        # additional parameters
        search_params = {'part':'snippet',
              'q':request.POST['search'],
              'order':'date', # for videos to be returned in reverse chronological order
              'maxResults': 9, # Specifies the number of videos returned
              'type': 'video', # only return video
              'key' : settings.YOUTUBE_DATA_API_KEY # In settings.py, api key is stored under this variable
              }
        video_ids = []          
        # request made
        r = requests.get(search_url,params=search_params)
        # Converting to json
        results = r.json()['items']

        for result in results:
            # Collecting all the video id's
            video_ids.append(result['id']['videoId'])
            video_params = {
            'key' : settings.YOUTUBE_DATA_API_KEY,
            'part' : 'snippet,contentDetails',
            'id' : ','.join(video_ids),
            'maxResults': 9
            }

        r = requests.get(video_url,params=video_params)

        results = r.json()['items']
        
        for result in results:
            video_data = {
                'title' : result['snippet']['title'],
                'id' : result['id'],
                'url' : f'https://www.youtube.com/watch?v={ result["id"] }',
                'thumbnail':result['snippet']['thumbnails']['high']['url']
            }
            videos.append(video_data)

    context = {
            'videos' : videos
            }       
    return render(request,'search/index.html',context)
# Making the api call every 10 minutes    
schedule.every(10).minutes.do(index)

# To run the tasks inn a blocking manner
while True:
    schedule.run_pending()
    time.sleep(1)     