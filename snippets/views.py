from snippets.models import Snippet
from snippets.serializers import SnippetSerializer
from rest_framework import mixins, generics


# Create your views here.

# class SnippetList(mixins.ListModelMixin,
#                   mixins.CreateModelMixin,
#                   generics.GenericAPIView):
#     """
#     List all code snippets, or create a new snippet
#     """
#     queryset = Snippet.objects.all()
#     serializer_class = SnippetSerializer
#
#     def get(self, request, *args, **kwargs):
#         return self.list(self, request, *args, **kwargs)
#
#     def post(self, request, *args, **kwargs):
#         return self.create(self, request, *args, **kwargs)
#
#
# class SnippetDetail(mixins.RetrieveModelMixin,
#                     mixins.UpdateModelMixin,
#                     mixins.DestroyModelMixin,
#                     generics.GenericAPIView):
#     """
#     Retrieve, update or delete a code snippet
#     """
#     queryset = Snippet.objects.all()
#     serializer_class = SnippetSerializer
#
#     def get(self, request, *args, **kwargs):
#         return self.retrieve(self, request, *args, **kwargs)
#
#     def put(self, request, *args, **kwargs):
#         return self.update(self, request, *args, **kwargs)
#
#     def delete(self, request, *args, **kwargs):
#         return self.destroy(self, request, *args, **kwargs)
class SnippetList(generics.ListCreateAPIView):
    queryset = Snippet.objects.all()
    serializer_class = SnippetSerializer


class SnippetDetail(generics.RetrieveUpdateDestroyAPIView):
    queryset = Snippet.objects.all()
    serializer_class = SnippetSerializer
