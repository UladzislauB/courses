from django.db import models


class Topic(models.Model):
    """Topic, that user learn"""
    text = models.CharField(max_length=200)
    date_added = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        """Return text representation of the model"""
        return self.text


class Entry(models.Model):
    """Information about topic"""
    topic = models.ForeignKey(Topic, on_delete=models.CASCADE)
    text = models.TextField()
    date_added = models.DateTimeField(auto_now_add=True)

    class Meta:
        verbose_name_plural = "entries"

    def __str__(self):
        if len(self.text) > 50:
            return self.text[:50] + "..."
        else:
            return self.text
