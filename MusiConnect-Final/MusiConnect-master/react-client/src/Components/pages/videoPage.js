import React, { Component } from 'react';

class VideoPage extends Component {
  render() {
    return (
      <div class="row">

        <div class="column side">
          <div class="syllabusInfoBox">
            <h2>Kent State Choir</h2>
            <h1>Video Gallery</h1>
            <br></br><br></br>
            <h4>This shows the compilationof videos for various groups within the Music Department.</h4>
            <br></br><br></br>
            <h4>Videos can be easily found with the search bar.</h4>
            <br></br>
          </div>
        </div>

        <div class="column middle">
          <h1>Video Page</h1>
            <iframe width="100%" height="640" id="ytHtml" src="../yt-search.html"></iframe>
        </div>


      </div>
    )
  }
}
export default VideoPage;