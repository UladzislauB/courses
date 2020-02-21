from django.urls import path
from . import views

urlpatterns = [
    path('', views.all_posts),
    path('<int:post_id>/', views.detail, name="detail")
]
