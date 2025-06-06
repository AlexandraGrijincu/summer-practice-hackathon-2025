from django.shortcuts import render, HttpResponse 
# Create your views here. 
def home(request): 
    return render(request, "index.html") 
def project(request): 
    return render(request, "project.html") 

