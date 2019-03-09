window.onscroll = function(){stickyNav(); autoclose_fun()};

function stickyNav(){
	var navigationbar = document.querySelector(".header__nav");
	var navbar_settop = navigationbar.offsetTop;
	if(window.pageYOffset > navbar_settop + 8){
		navigationbar.classList.add("sticky");
	}
	else{
		navigationbar.classList.remove("sticky");
	}
};

function autoclose_fun(){
	var mobnav = document.querySelector('.mobile-menu');
	var settop = mobnav.offsetTop;
	if(window.pageYOffset > settop + 300){
		mobnav.style.left = "-100%";
	}
};

document.querySelector('.mobile-menu__links').onclick = close_btn_fun;

function close_btn_fun(){
	var mobnav = document.querySelector('.mobile-menu');
	mobnav.style.left = "-100%";
};


document.querySelector('.button-hamburger').onclick = open_fun;

function open_fun(){
	document.querySelector('.mobile-menu').style.left = 0;
}

document.querySelector('.button-close').onclick = close_fun;

function close_fun(){
	document.querySelector('.mobile-menu').style.left = "-100%";
}


// <-- the trick to correct sizing -->
const setCorrectViewPort = () => {
	let vh = window.innerHeight * 0.01;
	document.documentElement.style.setProperty('--vh', `${vh}px`);

	window.addEventListener('resize', () => {
  let vh = window.innerHeight * 0.01;
  document.documentElement.style.setProperty('--vh', `${vh}px`);
});
};

setCorrectViewPort();
// <-- the trick to correct sizing -->



// <--  scroll into view -->
const scrollDownBtn = document.querySelector('.btn-scroll');
if (!!scrollDownBtn) {
  scrollDownBtn.addEventListener('click', (e) => {
    e.preventDefault();
    scrollDownBtn.scrollIntoView({
        behavior: 'smooth',
        block: 'start',
      });
  });
}
// <--  scroll into view -->


// <--  slice content -->
const containerInnerModule = document.querySelectorAll('.container-inner__module');

if (!!containerInnerModule) {
  const arrayFromContainerInnerModule = Array.from(containerInnerModule);
  arrayFromContainerInnerModule.forEach((container) => {
    const titleBlock = container.children[0];

    function checkHeight() {
      const textBlock = container.children[2];
      if (textBlock && titleBlock && titleBlock.scrollHeight < 94) {
        titleBlock.scrollHeight + textBlock.scrollHeight > 163 ? sliceContent(textBlock) : false;
      } else if (textBlock && titleBlock && titleBlock.scrollHeight >= 94) {
        sliceContent(titleBlock);
      }
    };

    function sliceContent(textBlock) {
      const content = textBlock.innerText.split(' ');
      const newContent = content.slice(content[content.length - 1], -1);
      textBlock.innerText = (newContent.join(' ') + '...').replace('....', '...');
      checkHeight();
    }

    checkHeight();
  });
}
// <--  slice content -->

