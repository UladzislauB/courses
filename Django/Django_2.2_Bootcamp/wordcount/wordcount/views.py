from django.shortcuts import render
import re


def home(request):
    return render(request, "home.html")


def count(request):
    fulltext = request.GET['fulltext']
    word_dictionary = {}
    word_list = re.findall(r"\w+", fulltext)
    for word in word_list:
        if word in word_dictionary:
            word_dictionary[word] += 1
        else:
            word_dictionary[word] = 1
    sorted_words = sorted(word_dictionary.items(), key=lambda x: x[1], reverse=True)
    return render(request, "count.html", {"fulltext": fulltext, "count_total": len(word_list),
                                          "word_dictionary": sorted_words})
