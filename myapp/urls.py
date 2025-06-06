from django.urls import path 
from . import views 
urlpatterns = [ 
    path('', views.home, name='index'), 
    path('project/', views.project, name='project'),
    path('post/<int:post_id>/', views.post_detail, name='post_detail'), 
    path('post/<int:post_id>/edit/', views.post_update, name='post_update'),
    path('submit-review/', views.submit_review, name='submit_review'),
    path('update-review/<int:review_id>/', views.update_review, name='update_review'), 
    path('delete-review/<int:review_id>/', views.delete_review, name='delete_review'), 

]
