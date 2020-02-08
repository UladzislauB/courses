from django.shortcuts import render
from .models import Topic


def index(request):
    """Home page of app learning_logs"""
    return render(request, 'learning_logs/index.html')


def topics(request):
    """Displays a list of topics"""
    topics = Topic.objects.order_by('date_added')
    context = {"topics": topics}
    return render(request, "learning_logs/topics.html", context)


def topic(request, topic_id):
    """Displays single topic and it's entries"""
    topic = Topic.objects.get(id=topic_id)
    entries = topic.entry_set.order_by('-date_added')
    context = {"topic": topic, "entries": entries}
    return render(request, "learning_logs/topic.html", context)
