from django.shortcuts import render, get_object_or_404, redirect
from .models import Post
from .models import Review 
from .forms import ReviewForm 


# Afișează toate postările pe pagina principală
def home(request):
    posts = Post.objects.all()
    reviews = Review.objects.all().order_by('-date') 

    return render(request, 'index.html', {'posts': posts,'reviews': reviews})

# Pagina „project”
def project(request):
    return render(request, 'project.html')

# Afișează detalii despre o postare
def post_detail(request, post_id):
    post = get_object_or_404(Post, pk=post_id)
    return render(request, 'post_detail.html', {'post': post})

# Permite editarea unei postări existente
def post_update(request, post_id):
    post = get_object_or_404(Post, id=post_id)

    if request.method == 'POST':
        title = request.POST.get('title')
        description = request.POST.get('description')

        post.title = title
        post.description = description
        post.save()

        return redirect('post_detail', post_id=post_id)

    return render(request, 'post_edit.html', {'post': post})

def submit_review(request): 
    if request.method == 'POST': 
        form = ReviewForm(request.POST) 
        if form.is_valid(): 
            form.save() 
            return redirect('index') 
    else:
        form = ReviewForm() 
    return render(request, './submit_review.html', {'form': form})

def update_review(request, review_id):
    review = get_object_or_404(Review, pk=review_id) 
    if request.method == 'POST': 
        form = ReviewForm(request.POST, instance=review) 
        if form.is_valid(): 
            form.save() 
            return redirect('index') 
    else: 
        form = ReviewForm(instance=review) 
    return render(request, './update_review.html', {'form': form}) 

def delete_review(request, review_id): 
    review = get_object_or_404(Review, pk=review_id) 
    if request.method == 'POST': 
        review.delete_review() 
        return redirect('index') 
    return render(request, './delete_review.html', {'review': review}) 
